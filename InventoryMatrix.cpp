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

void InventoryMatrix::SetStartIndex(int InIndex)
{
	StartIndex = InIndex;
}

int InventoryMatrix::GetSize()
{
	return ItemWidgetArray.size();
}

void InventoryMatrix::draw(sf::RenderTarget& WindowTarget)
{
	
	for (size_t i = StartIndex; i < ItemWidgetArray.size() && i < StartIndex + 10; i++)
	{
		ItemWidgetArray[i].Draw(WindowTarget);
	}
	
}
