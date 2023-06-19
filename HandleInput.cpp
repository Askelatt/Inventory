#include "HandleInput.h"

InputHandler::InputHandler()
    : ActiveWidget(-1, ItemWidget::WidgetState::Idle)
{

}

void InputHandler::handleInput(sf::RenderWindow& InWindow, const sf::Event& InEvent, std::vector<ItemWidget>& InWidgets, int InStartIndex, int InEndIndex)
{
    
    if (InEvent.type == sf::Event::MouseButtonPressed)
    {
        
        for (int i = InStartIndex; i < InEndIndex; ++i)
        {
            ItemWidget::WidgetState state = InWidgets[i].UpdateWidgetState(InWindow );
            if (state != ItemWidget::WidgetState::Idle)
            {
                ActiveWidget = std::make_pair(i, state);
                InitialText = getItemValue(InWidgets[ActiveWidget.first].OwnItem, ActiveWidget.second); // get and save initial value of parameter
                InWidgets[ActiveWidget.first].updateText();
            }
        }
    }
    else if (InEvent.type == sf::Event::TextEntered && ActiveWidget.second != ItemWidget::WidgetState::Idle)
    {
        if (InEvent.text.unicode > 31 && InEvent.text.unicode != 127)
        {
            char typedChar = static_cast<char>(InEvent.text.unicode);

            switch (ActiveWidget.second)
            {
            case ItemWidget::WidgetState::Btn_Active_Name:
                InWidgets[ActiveWidget.first].OwnItem.SetItemName(getItemValue(InWidgets[ActiveWidget.first].OwnItem, ActiveWidget.second) + typedChar);
                break;
            case ItemWidget::WidgetState::Btn_Active_Description:
                InWidgets[ActiveWidget.first].OwnItem.SetItemDescription(getItemValue(InWidgets[ActiveWidget.first].OwnItem, ActiveWidget.second) + typedChar);
                break;
            case ItemWidget::WidgetState::Btn_Active_Location:
                InWidgets[ActiveWidget.first].OwnItem.SetItemLocation(getItemValue(InWidgets[ActiveWidget.first].OwnItem, ActiveWidget.second) + typedChar);
                break;
            case ItemWidget::WidgetState::Btn_Active_Quantity:
                if (std::isdigit(typedChar))
                {
                    InWidgets[ActiveWidget.first].OwnItem.SetItemQuantity(std::stoi(std::to_string(InWidgets[ActiveWidget.first].OwnItem.GetItemQuantity()) + typedChar));
                }
                break;
            case ItemWidget::WidgetState::Btn_Active_ID:
                if (std::isdigit(typedChar))
                {
                    InWidgets[ActiveWidget.first].OwnItem.SetItemID(std::stoi(std::to_string(InWidgets[ActiveWidget.first].OwnItem.GetItemID()) + typedChar));
                }
                break;
            }
            InWidgets[ActiveWidget.first].updateText();
        }
    }
    else if (InEvent.type == sf::Event::KeyPressed && InEvent.key.code == sf::Keyboard::BackSpace && ActiveWidget.second != ItemWidget::WidgetState::Idle)
    {
        switch (ActiveWidget.second)
        {
        case ItemWidget::WidgetState::Btn_Active_Name:
            if (!InWidgets[ActiveWidget.first].OwnItem.GetItemName().empty())
            {
                InWidgets[ActiveWidget.first].OwnItem.SetItemName(getItemValue(InWidgets[ActiveWidget.first].OwnItem, ActiveWidget.second).substr(0, getItemValue(InWidgets[ActiveWidget.first].OwnItem, ActiveWidget.second).size() - 1));
            }
            break;
        case ItemWidget::WidgetState::Btn_Active_Description:
            if (!InWidgets[ActiveWidget.first].OwnItem.GetItemDescription().empty())
            {
                InWidgets[ActiveWidget.first].OwnItem.SetItemDescription(getItemValue(InWidgets[ActiveWidget.first].OwnItem, ActiveWidget.second).substr(0, getItemValue(InWidgets[ActiveWidget.first].OwnItem, ActiveWidget.second).size() - 1));
            }
            break;
        case ItemWidget::WidgetState::Btn_Active_Location:
            if (!InWidgets[ActiveWidget.first].OwnItem.GetItemLocation().empty())
            {
                InWidgets[ActiveWidget.first].OwnItem.SetItemLocation(getItemValue(InWidgets[ActiveWidget.first].OwnItem, ActiveWidget.second).substr(0, getItemValue(InWidgets[ActiveWidget.first].OwnItem, ActiveWidget.second).size() - 1));
            }
            break;
        case ItemWidget::WidgetState::Btn_Active_Quantity:
            InWidgets[ActiveWidget.first].OwnItem.SetItemQuantity(InWidgets[ActiveWidget.first].OwnItem.GetItemQuantity() / 10);
            break;
        case ItemWidget::WidgetState::Btn_Active_ID:
            InWidgets[ActiveWidget.first].OwnItem.SetItemID(InWidgets[ActiveWidget.first].OwnItem.GetItemID() / 10);
            break;
        }
        InWidgets[ActiveWidget.first].updateText();
    }
    else if (InEvent.type == sf::Event::KeyPressed && InEvent.key.code == sf::Keyboard::Enter && ActiveWidget.second != ItemWidget::WidgetState::Idle)
    {
       //save final value after Enter was pressed
        std::string newValue = getItemValue(InWidgets[ActiveWidget.first].OwnItem, ActiveWidget.second);
        //reset of active widget after saving of value
        ActiveWidget = std::make_pair(-1, ItemWidget::WidgetState::Idle);
    }
    else if (InEvent.type == sf::Event::KeyPressed && InEvent.key.code == sf::Keyboard::Escape && ActiveWidget.second != ItemWidget::WidgetState::Idle)
    {
        // return initial value if Escape was pressed
        setItemValue(InWidgets[ActiveWidget.first].OwnItem, ActiveWidget.second, InitialText);
        InWidgets[ActiveWidget.first].updateText();

         //reset of active widget after returning of initial value
        ActiveWidget = std::make_pair(-1, ItemWidget::WidgetState::Idle);
    }
}

std::string InputHandler::getItemValue(const Item& item, ItemWidget::WidgetState widgetState)
{
    switch (widgetState)
    {
    case ItemWidget::WidgetState::Btn_Active_Name:
        return item.GetItemName();
    case ItemWidget::WidgetState::Btn_Active_Description:
        return item.GetItemDescription();
    case ItemWidget::WidgetState::Btn_Active_Location:
        return item.GetItemLocation();
    default:
        return "";
    }
}

void InputHandler::setItemValue(Item& InItem, ItemWidget::WidgetState InWidgetState, const std::string& InValue)
{
    switch (InWidgetState)
    {
    case ItemWidget::WidgetState::Btn_Active_Name:
        InItem.SetItemName(InValue);
        break;
    case ItemWidget::WidgetState::Btn_Active_Description:
        InItem.SetItemDescription(InValue);
        break;
    case ItemWidget::WidgetState::Btn_Active_Location:
        InItem.SetItemLocation(InValue);
        break;
    }
}
