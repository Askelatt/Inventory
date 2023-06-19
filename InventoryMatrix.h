#pragma once
#include "ItemWidget.h"
#include "Inventory.h"

class InventoryMatrix
{
private:
	sf::Font TextFont;
	std::vector <ItemWidget> ItemWidgetArray;

	void initWidgetArray(Inventory& InInventory);

	

public:

	InventoryMatrix(Inventory& InInventory);

	std::vector <ItemWidget>& GetWidgets();
	int StartIndex = 0;
	void SetStartIndex(int InIndex);
	int GetSize();
	void draw(sf::RenderTarget& WindowTarget);
};

