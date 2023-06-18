#include "Inventory.h"
#include "XMLDataHandler.h"
#include "GUI.h"



int main()
{
	Inventory InitInventory;
	XMLDataHandler DataHand;
	
	DataHand.LoadInventoryFromFile(InitInventory);
	GUI gui(InitInventory);
	gui.runApp(InitInventory);
	return 0;
}