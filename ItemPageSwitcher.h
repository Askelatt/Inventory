#pragma once
#include "Button.h"
#include "InventoryMatrix.h"
#include <iostream>

class ItemPageSwitcher : public Button
{
public:

	ItemPageSwitcher(InventoryMatrix& InMatrix, int InItemsPerPage);

	bool Click(sf::RenderWindow& InWindow) override;
	void Draw(sf::RenderTarget& Target) const override;

	int GetStartIndex();
private:

	InventoryMatrix& ItemMatrix;

	std::shared_ptr<sf::Texture> ButtonTextureArrowLeft;
	std::shared_ptr<sf::Texture> ButtonTextureArrowRight;

	sf::Sprite ButtonSpriteArrowLeft;
	sf::Sprite ButtonSpriteArrowRight;

	int ItemsPerPage;
	int StartIndex;

};

