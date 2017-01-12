#pragma once

#include "Restaurant.h"
#include <list>

class RestaurantList
{
	public:	
		//Provides access to the internal list of restaurants
		const std::list<Restaurant>& GetData() const;
		//Populates the internal list of restaurants ,'dataList', with the file contents
		void LoadFromFile(char* fileName);				
	private:
		//Contains the list of restaurants
		std::list<Restaurant> dataList;	
};
