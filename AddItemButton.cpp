#include "AddItemButton.h"

AddItemButton::AddItemButton(InventoryMatrix& InMatrix)
{
	ButtonTexture = std::make_shared<sf::Texture>();

	if (!ButtonTexture->loadFromFile("..\\SFML_inv\\Textures\\AddButton\\Plus.png"))
	{
		std::cout << "Failed to load texture for Add Button" << std::endl;
	}

	ButtonSprite.setTexture(*ButtonTexture);
	ButtonSprite.setPosition(InMatrix.GetWidgets()[0].GetPosition().x + 1450, InMatrix.GetWidgets()[0].GetPosition().y - 45);
}

bool AddItemButton::Click(sf::RenderWindow& InWindow)
{
	sf::Vector2i PixelPos = sf::Mouse::getPosition(InWindow);
	sf::Vector2f WorldPos = InWindow.mapPixelToCoords(PixelPos);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (ButtonSprite.getGlobalBounds().contains(WorldPos))
		{
			return true;
		}
	}
	return false;
}

void AddItemButton::Draw(sf::RenderTarget& Target) const
{
	Target.draw(ButtonSprite);
}
