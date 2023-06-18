#pragma once
#include "string"
class Item
{
public:
	//Constructors
	Item(const std::string& InItemName, const std::string& InItemDescription, const std::string& InItemLocation, int InItemQuantity, int InItemID);

	//Accessors
	const std::string GetItemName() const;
	const std::string GetItemDescription() const;
	const std::string GetItemLocation() const;
	int GetItemQuantity() const;
	int GetItemID() const;

	//Modifiers
	void SetItemName(std::string InItemName);
	void SetItemDescription(std::string InItemDescription);
	void SetItemLocation(std::string InItemLocation);
	void SetItemQuantity(int InItemQuantity);
	void SetItemID(int InItemID);

private:

	std::string ItemName;
	std::string ItemDescription;
	std::string ItemLocation;
	int ItemQuantity;
	int ItemID;

};

