#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "ItemWidget.h"

class InputHandler
{
public:
    InputHandler();

    void handleInput(sf::RenderWindow& InWindow, const sf::Event& event, std::vector<ItemWidget>& widgets, int startIndex, int endIndex);

private:
    std::pair<int, ItemWidget::WidgetState> activeWidget;
    std::string initialText;

    std::string getItemValue(const Item& item, ItemWidget::WidgetState widgetState);
    void setItemValue(Item& item, ItemWidget::WidgetState widgetState, const std::string& value);
};
