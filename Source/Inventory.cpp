#include "Inventory.h"
#include "Exceptions.h"
#include <cstring>
#include <fstream>
#include <cstdlib>

Inventory::Inventory()
{
	memset(this->data,0,sizeof(this->data));
}
unsigned int Inventory::GetAmount(INVENTORYTYPE type) const
{
	if ( (type < NORESTRICTION) || (type > FISHFREE) )
		throw new ArrayOutOfRange;
	return this->data[type];
}
unsigned int Inventory::GetTotalAmount() const
{
	unsigned int result = 0;
	for(int i =0; i<INVENTORYTYPESIZE;i++)
	{
		result += this->data[i];
	}
	return result;
}
void Inventory::LoadFromFile(char* fileName)	
{
	if(!fileName)
		throw new FileOpenError;
	
	memset(this->data,0,sizeof(this->data));
	
	std::ifstream file(fileName);
	if(!file.is_open())
		throw new FileOpenError;
	
	char buffer[256];
	unsigned int invType = 0;
	int tempInt = 0;
	while(!file.eof() && (invType < INVENTORYTYPESIZE))
	{
		file.getline(buffer,sizeof(buffer),',');		
		tempInt = atoi(buffer);
		if(tempInt < 0)
			tempInt = 0;
		this->data[invType++] = tempInt;		
	}		
	file.close();
}
void Inventory::SetAmount(INVENTORYTYPE type, unsigned int value)
{
	if ( (type < NORESTRICTION) || (type > FISHFREE) )
		throw new ArrayOutOfRange;
	this->data[type] = value;
}