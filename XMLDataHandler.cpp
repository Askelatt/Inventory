#include "XMLDataHandler.h"

 void XMLDataHandler::LoadInventoryFromFile(Inventory& InInvetory)
{
	tinyxml2::XMLDocument InXMLDocument;
	InXMLDocument.LoadFile(FileName.c_str());
	tinyxml2::XMLElement* Root = InXMLDocument.FirstChildElement("Inventory");
	tinyxml2::XMLElement* Item = Root->FirstChildElement("Item");

	while (Item != nullptr)
	{
		InItemsArray.emplace_back(Item->Attribute("name"),
								  Item->Attribute("description"),
								  Item->Attribute("location"),
								  Item->IntAttribute("quantity"),
								  Item->IntAttribute("ID"));

		Item = Item->NextSiblingElement("Item");
	}
	InInvetory.InitInvetory(this->InItemsArray);
}

void XMLDataHandler::saveInventoryToFile(const std::vector<Item> InItemsArray)
{
	tinyxml2::XMLDocument InXMLDocument;
	InXMLDocument.LoadFile("inventory.xml");
	tinyxml2::XMLElement* Root = InXMLDocument.FirstChildElement("Inventory");
	tinyxml2::XMLElement* Item = Root->FirstChildElement("Item");
	for (auto& InItem : InItemsArray)
	{
		Item->SetAttribute("name", InItem.GetItemName().c_str());
		Item->SetAttribute("description", InItem.GetItemDescription().c_str());
		Item->SetAttribute("location", InItem.GetItemLocation().c_str());
		Item->SetAttribute("quantity", InItem.GetItemQuantity());
		Item->SetAttribute("ID", InItem.GetItemID());
		
		Item = Item->NextSiblingElement("Item");
	}
	InXMLDocument.SaveFile("inventory.xml");
	std::cout << "Inventory was saved" << std::endl;
}
