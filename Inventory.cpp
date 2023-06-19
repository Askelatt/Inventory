#include "Inventory.h"

void Inventory::AddItem()
{
	Item InItem{ "0", "0", "0", 0, GetSize() + 1 };
	ItemsArray.push_back(InItem);
	std::cout << "Item was added to inventory " << std::endl;
}

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

