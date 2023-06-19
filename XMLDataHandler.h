#pragma once
#include "tinyxml2.h"
#include "Inventory.h"
#include <string>
#include <iostream>
class XMLDataHandler
{

private:

	std::string FileName = "inventory.xml";
	std::vector <Item> InItemsArray;

public:

	void LoadInventoryFromFile(Inventory& InInvetory);
	void saveInventoryToFile(const std::vector<Item> InItemsArray);
	void addItemToFile();
	

};

