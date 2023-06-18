#include "InventoryMatrix.h"

InventoryMatrix::InventoryMatrix(Inventory& InInventory)
{
	TextFont.loadFromFile("arial.ttf");
	initWidgetArray(InInventory);
}

std::vector<ItemWidget>& InventoryMatrix::GetWidgets()
{
	return ItemWidgetArray;
}

void InventoryMatrix::initWidgetArray(Inventory& InInventory)
{
	for (size_t i = 0; i < InInventory.GetSize(); i++)
	{
		ItemWidget Widget(InInventory.GetInventory()[i], "", TextFont);
		ItemWidgetArray.push_back(Widget);
	}
}

void InventoryMatrix::draw(sf::RenderTarget& WindowTarget)
{
	
	for (size_t i = 0; i < ItemWidgetArray.size() && i < 10; i++)
	{
		ItemWidgetArray[i].Draw(WindowTarget);
	}
	
}
