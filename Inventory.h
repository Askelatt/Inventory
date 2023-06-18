#pragma once
#include <vector>
#include "Item.h"
#include <iostream>

class Inventory
{
private:

	std::vector <Item> ItemsArray;

public:

	void AddItem();
	void DeleteItem();
	void InitInvetory(std::vector <Item> InItemsArray);
	void SaveInventory(std::vector<Item> InItemsArray);

	int GetSize();

	std::vector <Item>& GetInventory();
};

