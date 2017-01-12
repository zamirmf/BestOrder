#pragma once

#include "Inventory.h"
#include <string>

class Restaurant
{
	public:		
		//Initializes member variables
		Restaurant();				
		//Provides access to the restaurant inventory (through its reference)
		Inventory& GetInventory();
		//Returns the name of the restaurant
		const char* GetName() const;
		//Returns the restaurant rating
		unsigned int GetRating() const;
		//Updates the restaurant name
		void SetName(char* name);	
		//Updates the restaurant rating	
		void SetRating(unsigned int rating);				
		//To be used by the method Sort. Rating is the first attribute to be taken into consideration, followed by the number of food units.
		bool operator<(const Restaurant& obj) const;		
	private:
		//Contains the restaurant inventory
		Inventory inventory;	
		//Contains the restaurant name
		std::string name;
		//Contains the restaurant rating
		unsigned int rating;		
};