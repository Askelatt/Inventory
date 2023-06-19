#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "ItemWidget.h"

class InputHandler
{
public:
    InputHandler();

    void handleInput(sf::RenderWindow& InWindow, const sf::Event& Event, std::vector<ItemWidget>& Widgets, int StartIndex, int EndIndex);

private:
    std::pair<int, ItemWidget::WidgetState> ActiveWidget;
    std::string InitialText;

    std::string getItemValue(const Item& Item, ItemWidget::WidgetState WidgetState);
    void setItemValue(Item& item, ItemWidget::WidgetState WidgetState, const std::string& Value);
};
