#include "Inventory.h"

void Inventory::InitInvetory(std::vector<Item> InItemsArray)
{
	this->ItemsArray = InItemsArray;
}

void Inventory::SaveInventory(std::vector<Item> InItemsArray)
{

}

int Inventory::GetSize()
{
	return ItemsArray.size();
}

std::vector<Item>& Inventory::GetInventory()
{
	return ItemsArray;
}

