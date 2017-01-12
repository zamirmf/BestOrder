#include "OrderManager.h"
#include "Inventory.h"
#include "Restaurant.h"
#include "RestaurantList.h"
#include "Exceptions.h"
#include <fstream>

OrderManager::OrderManager() : remainingOrder(0)
{
	
}
void OrderManager::CalculateBestOrder(const Inventory& customerOrder, const RestaurantList& restaurantList)
{
	//Clear the previous state (if applied)
	this->Reset();
	
	//Create a copy of customer order and one of the list of restaurants
	Inventory copyCustOrder(customerOrder);
	std::list<Restaurant> copyRestList(restaurantList.GetData());
	std::list<Restaurant>::iterator restListIt = copyRestList.begin();

	//reference values used as a benchmark while iterating through the list of restaurants
	unsigned int maximumAmount;
	unsigned int maximumRating;
	std::list<Restaurant>::iterator maximumIt;
	while(copyCustOrder.GetTotalAmount())
	{
		maximumAmount = 0;
		maximumRating = 0;		
		//Iterates through the list of restaurants looking for the one which maximizes the number of food units (considering the highest rating first)
		for(restListIt = copyRestList.begin(); restListIt != copyRestList.end(); restListIt++)
		{
			//Exit the loop if the current rating is lesser than the a already evaluated rating
			if (restListIt->GetRating() < maximumRating)
				break;
			//Skip the iteration if there is no food unit available in a restaurant
			if (restListIt->GetInventory().GetTotalAmount() <= 0)
				continue;
			
			//Set point system on each restaurant based on the amount of food available which matches the required amount of food.
			unsigned int totalAmount = 0;			
			for(int i =0; i < Inventory::INVENTORYTYPESIZE;i++)
			{
				const Inventory::INVENTORYTYPE invType = (Inventory::INVENTORYTYPE)i;
				unsigned int requiredAmount = copyCustOrder.GetAmount(invType);
				unsigned int availableAmount = restListIt->GetInventory().GetAmount(invType);	
				totalAmount += (requiredAmount < availableAmount)? requiredAmount : availableAmount;								
			}			
			//Pick the restaurant with the highest points up to this iteration
			if (totalAmount > maximumAmount && restListIt->GetRating() >= maximumRating)
			{
				maximumAmount = totalAmount;
				maximumIt = restListIt;
				maximumRating = restListIt->GetRating();				
			}
		}		
		//It requires at least one restaurant to be succeeded in the previous loop. If more than one, then the highest one is the one picked. 
		if (maximumAmount)
		{
			//Add a new order based on the restaurant with maximum points and updates its remaining products. Also updates the customer order.					
			Inventory newOrder;			
			for(int i =0; i < Inventory::INVENTORYTYPESIZE;i++)
			{
				const Inventory::INVENTORYTYPE invType = (Inventory::INVENTORYTYPE)i;
				unsigned int requiredAmount = copyCustOrder.GetAmount(invType);
				unsigned int availableAmount = maximumIt->GetInventory().GetAmount(invType);	
				newOrder.SetAmount(invType,(requiredAmount < availableAmount)? requiredAmount : availableAmount);
				requiredAmount -= newOrder.GetAmount(invType);
				availableAmount -= newOrder.GetAmount(invType);
				//Update copy order and copy rest list				
				copyCustOrder.SetAmount(invType,requiredAmount);
				maximumIt->GetInventory().SetAmount(invType, availableAmount);
			}							
			this->orderList.push_back(NameAndOrderPair(std::string(maximumIt->GetName()),newOrder));		
		}
		//If no restaurant succeeded in the previous loop, it means that the remaining customer order cannot be fulfilled
		else
		{
			this->remainingOrder = copyCustOrder.GetTotalAmount();			
			break;
		}
	}			
}
void OrderManager::Reset()
{		
	this->orderList.clear();
	this->remainingOrder = 0;
}
void OrderManager::SaveToFile(char* fileName) const
{
	if(!fileName)
		throw new FileOpenError;
	
	std::ofstream file(fileName,std::ios_base::out|std::ios_base::trunc);
	if(!file.is_open())
		throw new FileOpenError;
	
	file << "---Final Order Begins---\n\n";	
	
	if(!this->orderList.size())
		file << "SOLUTION: there are no restaurants able to provide the requested order.\n";
	else
	{
		file << "SOLUTION: the best order would be the following:\n";
		for(std::list<NameAndOrderPair>::const_iterator it= this->orderList.begin(); it != this->orderList.end(); it++)
		{
			file <<"Name: "<< it->first << std::endl;
			for(int i =0; i < Inventory::INVENTORYTYPESIZE;i++)
			{
				const Inventory::INVENTORYTYPE invType = (Inventory::INVENTORYTYPE)i;
				if(!it->second.GetAmount(invType))
					continue;
				if (i == 0)
					file << "No restriction food: ";
				else if (i == 1)
					file << "Vegetarian food: ";
				else if (i == 2)
					file << "Gluten-free food: ";			
				else if (i == 3)
					file << "Nut-free food: ";			
				else if (i == 4)
					file << "Fish-free food: ";			
				file << it->second.GetAmount(invType) << std::endl;
			}
			file << std::endl;
		}		
		if (this->remainingOrder)
			file << "NOTE: the current set of restaurants can't cover the whole order (" << this->remainingOrder << " items are left).\n";
	}	
	file << "\n---Final Order Ends---";		
	file.close();	
}