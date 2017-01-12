#include "RestaurantList.h"
#include "Inventory.h"
#include "OrderManager.h"
#include "ErrorLog.h"
#include <exception>

int main(int argc, char* argv[])
{   
	//Expects three parameters (all file names) in addition to the executable file name: (1) customer order, (2) restaurant list and (3) final order
	if (argc < 4)
	{
		 ErrorLog::GetInstance() << "Initialization Error. Not enough command-line parameters.";     	 
		 return -1;
	}
    char* customerOrderFName = argv[1];
	char* restaurantStocksFName = argv[2];
	char* finalOrderFName = argv[3];
	
	RestaurantList restaurantList;
	Inventory customerOrder;
	OrderManager orderManager;

	try   
	{
		customerOrder.LoadFromFile(customerOrderFName);
		restaurantList.LoadFromFile(restaurantStocksFName);
		orderManager.CalculateBestOrder(customerOrder, restaurantList);
		orderManager.SaveToFile(finalOrderFName);
	}
	catch(std::exception* ex)
	{
		ErrorLog::GetInstance() << ex->what();
		return -1;
	}
	return 0;  
}
