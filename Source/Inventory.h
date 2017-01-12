#pragma once

class Inventory
{
	public:
		//Wraps different types of food into a single data structure
		enum INVENTORYTYPE
			{
				NORESTRICTION=0,
				VEGETARIAN,
				GLUTENFREE,
				NUTFREE,
				FISHFREE,
				INVENTORYTYPESIZE
			};	
		//Initializes member variables
		Inventory();
		//Returns the number of units available for a given type
		unsigned int GetAmount(INVENTORYTYPE type) const;		
		//Returns the sum of the number of units available for all types of food
		unsigned int GetTotalAmount() const;
		//Populates member variable 'data' based on the file content
		void LoadFromFile(char* fileName);	
		//Updates the number of units for a given type
		void SetAmount(INVENTORYTYPE type, unsigned int value);		
	private:
		//Contains the number of unit for each food type
		unsigned int data[INVENTORYTYPESIZE];
};