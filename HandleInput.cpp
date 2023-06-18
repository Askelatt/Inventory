#include "HandleInput.h"

InputHandler::InputHandler()
    : activeWidget(-1, ItemWidget::WidgetState::Idle)
{

}

void InputHandler::handleInput(sf::Window& InWindow, const sf::Event& event, std::vector<ItemWidget>& widgets)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(InWindow));
        for (int i = 0; i < widgets.size(); ++i)
        {
            ItemWidget::WidgetState state = widgets[i].UpdateWidgetState(mousePos);
            if (state != ItemWidget::WidgetState::Idle)
            {
                activeWidget = std::make_pair(i, state);
                initialText = getItemValue(widgets[activeWidget.first].OwnItem, activeWidget.second); // get and save initial value of parameter
                widgets[activeWidget.first].updateText();
            }
        }
    }
    else if (event.type == sf::Event::TextEntered && activeWidget.second != ItemWidget::WidgetState::Idle)
    {
        if (event.text.unicode > 31 && event.text.unicode != 127)
        {
            char typedChar = static_cast<char>(event.text.unicode);

            switch (activeWidget.second)
            {
            case ItemWidget::WidgetState::Btn_Active_Name:
                widgets[activeWidget.first].OwnItem.SetItemName(getItemValue(widgets[activeWidget.first].OwnItem, activeWidget.second) + typedChar);
                break;
            case ItemWidget::WidgetState::Btn_Active_Description:
                widgets[activeWidget.first].OwnItem.SetItemDescription(getItemValue(widgets[activeWidget.first].OwnItem, activeWidget.second) + typedChar);
                break;
            case ItemWidget::WidgetState::Btn_Active_Location:
                widgets[activeWidget.first].OwnItem.SetItemLocation(getItemValue(widgets[activeWidget.first].OwnItem, activeWidget.second) + typedChar);
                break;
            case ItemWidget::WidgetState::Btn_Active_Quantity:
                if (std::isdigit(typedChar))
                {
                    widgets[activeWidget.first].OwnItem.SetItemQuantity(std::stoi(std::to_string(widgets[activeWidget.first].OwnItem.GetItemQuantity()) + typedChar));
                }
                break;
            case ItemWidget::WidgetState::Btn_Active_ID:
                if (std::isdigit(typedChar))
                {
                    widgets[activeWidget.first].OwnItem.SetItemID(std::stoi(std::to_string(widgets[activeWidget.first].OwnItem.GetItemID()) + typedChar));
                }
                break;
            }
            widgets[activeWidget.first].updateText();
        }
    }
    else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::BackSpace && activeWidget.second != ItemWidget::WidgetState::Idle)
    {
        switch (activeWidget.second)
        {
        case ItemWidget::WidgetState::Btn_Active_Name:
            if (!widgets[activeWidget.first].OwnItem.GetItemName().empty())
            {
                widgets[activeWidget.first].OwnItem.SetItemName(getItemValue(widgets[activeWidget.first].OwnItem, activeWidget.second).substr(0, getItemValue(widgets[activeWidget.first].OwnItem, activeWidget.second).size() - 1));
            }
            break;
        case ItemWidget::WidgetState::Btn_Active_Description:
            if (!widgets[activeWidget.first].OwnItem.GetItemDescription().empty())
            {
                widgets[activeWidget.first].OwnItem.SetItemDescription(getItemValue(widgets[activeWidget.first].OwnItem, activeWidget.second).substr(0, getItemValue(widgets[activeWidget.first].OwnItem, activeWidget.second).size() - 1));
            }
            break;
        case ItemWidget::WidgetState::Btn_Active_Location:
            if (!widgets[activeWidget.first].OwnItem.GetItemLocation().empty())
            {
                widgets[activeWidget.first].OwnItem.SetItemLocation(getItemValue(widgets[activeWidget.first].OwnItem, activeWidget.second).substr(0, getItemValue(widgets[activeWidget.first].OwnItem, activeWidget.second).size() - 1));
            }
            break;
        case ItemWidget::WidgetState::Btn_Active_Quantity:
            widgets[activeWidget.first].OwnItem.SetItemQuantity(widgets[activeWidget.first].OwnItem.GetItemQuantity() / 10);
            break;
        case ItemWidget::WidgetState::Btn_Active_ID:
            widgets[activeWidget.first].OwnItem.SetItemID(widgets[activeWidget.first].OwnItem.GetItemID() / 10);
            break;
        }
        widgets[activeWidget.first].updateText();
    }
    else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter && activeWidget.second != ItemWidget::WidgetState::Idle)
    {
       //save final value after Enter was pressed
        std::string newValue = getItemValue(widgets[activeWidget.first].OwnItem, activeWidget.second);
        //reset of active widget after saving of value
        activeWidget = std::make_pair(-1, ItemWidget::WidgetState::Idle);
    }
    else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape && activeWidget.second != ItemWidget::WidgetState::Idle)
    {
        // return initial value if Escape was pressed
        setItemValue(widgets[activeWidget.first].OwnItem, activeWidget.second, initialText);
        widgets[activeWidget.first].updateText();

         //reset of active widget after returning of initial value
        activeWidget = std::make_pair(-1, ItemWidget::WidgetState::Idle);
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

void InputHandler::setItemValue(Item& item, ItemWidget::WidgetState widgetState, const std::string& value)
{
    switch (widgetState)
    {
    case ItemWidget::WidgetState::Btn_Active_Name:
        item.SetItemName(value);
        break;
    case ItemWidget::WidgetState::Btn_Active_Description:
        item.SetItemDescription(value);
        break;
    case ItemWidget::WidgetState::Btn_Active_Location:
        item.SetItemLocation(value);
        break;
    }
}
