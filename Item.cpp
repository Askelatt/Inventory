#include "Item.h"

Item::Item(const std::string& InItemName, const std::string& InItemDescription, const std::string& InItemLocation, int InItemQuantity, int InItemID)
    : ItemName(InItemName), ItemDescription(InItemDescription), ItemLocation(InItemLocation), ItemQuantity(InItemQuantity), ItemID(InItemID)
{

}

const std::string Item::GetItemName() const
{
    return this->ItemName;
}

const std::string Item::GetItemDescription() const
{
    return this->ItemDescription;
}

const std::string Item::GetItemLocation() const
{
    return this->ItemLocation;
}

int Item::GetItemQuantity() const
{
    return this->ItemQuantity;
}

int Item::GetItemID() const
{
    return this->ItemID;
}

void Item::SetItemName(std::string InItemName)
{
    this->ItemName = InItemName;
}

void Item::SetItemDescription(std::string InItemDescription)
{
    this->ItemDescription = InItemDescription;
}

void Item::SetItemLocation(std::string InItemLocation)
{
    this->ItemLocation = InItemLocation;
}

void Item::SetItemQuantity(int InItemQuantity)
{
    this->ItemQuantity = InItemQuantity;
}

void Item::SetItemID(int InItemID)
{
    this->ItemID = InItemID;
}
