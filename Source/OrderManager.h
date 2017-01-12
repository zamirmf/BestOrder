#pragma once

#include <list>
#include <string>

class Inventory;
class RestaurantList;

class OrderManager
{
	public:
		//Initializes member variables
		OrderManager();		
		//Calculate best order maximizing the food quality (based on the restaurant rating)
		void CalculateBestOrder(const Inventory& customerOrder, const RestaurantList& restaurantList);
		//Erases the list of orders and number of remaining orders
		void Reset();		
		//Save the list of orders to file
		void SaveToFile(char* fileName) const;		
	private:
		typedef std::pair<std::string,Inventory> NameAndOrderPair;
		//Contains the most recent calculated list of orders
		std::list<NameAndOrderPair> orderList;
		//Contains the remaing orders, i.e., not able to be provided by the available restaurants
		unsigned int remainingOrder;	
};