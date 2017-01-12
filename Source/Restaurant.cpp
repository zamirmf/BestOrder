#include "Restaurant.h"

Restaurant::Restaurant() : rating(0)
{
	
}
Inventory& Restaurant::GetInventory()
{
	return this->inventory;
}
const char* Restaurant::GetName() const
{
	return this->name.c_str();
}
unsigned int Restaurant::GetRating() const
{
	return this->rating;
}
void Restaurant::SetName(char* name)
{
	this->name = name;
}
void Restaurant::SetRating(unsigned int rating)
{
	this->rating = rating;
}
bool Restaurant::operator<(const Restaurant& obj) const
{
	if( (this->rating > obj.rating) ||
	    ((this->rating == obj.rating) && (this->inventory.GetTotalAmount() > obj.inventory.GetTotalAmount())) )
		return true;
	return false;
}
