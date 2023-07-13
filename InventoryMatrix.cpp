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

void InventoryMatrix::UpdateWidgetArray(Inventory& InInventory)
{
	ItemWidgetArray.clear();
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
	std::cout << "START " << std::endl;
	for (size_t i = StartIndex; i < ItemWidgetArray.size() && i < StartIndex + 10; i++)
	{
		std::cout << "i is : " << i << std::endl;
		ItemWidgetArray[i].Draw(WindowTarget);
	}
	
}
