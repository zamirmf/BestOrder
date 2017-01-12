#include "RestaurantList.h"
#include <fstream>
#include "Exceptions.h"
#include <cstdlib>
#include <cstring>

const std::list<Restaurant>& RestaurantList::GetData() const
{
	return this->dataList;
}
void RestaurantList::LoadFromFile(char* fileName)
{
	if (!fileName)
		throw new FileOpenError;
	
	dataList.clear();
	
	std::ifstream file(fileName);
	if(!file.is_open())
		throw new FileOpenError;
	
	char buffer[256];
	char* tempPtr = 0;
	int tempInt = 0;
	unsigned int invType = 0;
	while(!file.eof())
	{		
		file.getline(buffer,sizeof(buffer),'\n');	
		if (!std::strlen(buffer))
			continue;
		
		tempPtr = std::strtok(buffer,",");							
		if(!tempPtr)
			throw new FileWrongFormat;		
		
		Restaurant restaurant;				
		restaurant.SetName(tempPtr);		
		
		tempPtr = std::strtok(NULL,",");		
		if(!tempPtr)
			throw new FileWrongFormat;
		
		tempInt = atoi(tempPtr);
		if (tempInt < 0)
			tempInt = 0;
		restaurant.SetRating(tempInt);
		
		tempPtr = std::strtok(NULL,",");
		if(!tempPtr)
			throw new FileWrongFormat;
				
		invType = 0;		
		while(tempPtr)		
		{			
			tempInt = atoi(tempPtr);
			if (tempInt < 0)
				tempInt = 0;
			restaurant.GetInventory().SetAmount((Inventory::INVENTORYTYPE)invType++,tempInt);					
			tempPtr = std::strtok(NULL,",");			
		}
		
		if (invType != Inventory::INVENTORYTYPESIZE)
			throw new FileWrongFormat;
		
		dataList.push_back(restaurant);		
	}	
	file.close();	
	dataList.sort();
}
