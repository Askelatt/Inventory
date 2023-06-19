#pragma once
#include "Button.h"
#include "InventoryMatrix.h"
#include "iostream"

class AddItemButton : public Button
{
public:

	AddItemButton(InventoryMatrix& InMatrix);

	bool Click(sf::RenderWindow& InWindow) override;
	void Draw(sf::RenderTarget& Target) const override;

private:

	std::shared_ptr<sf::Texture> ButtonTexture;

	sf::Sprite ButtonSprite;
};

