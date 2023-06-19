#pragma once
#include "SFML\Graphics.hpp"

class Button
{
public:
	Button();

	virtual ~Button();


	virtual bool Click(sf::RenderWindow& InWindow) = 0;
	virtual void Draw(sf::RenderTarget& Target) const = 0;

private:

	std::shared_ptr<sf::Texture> ButtonTexture;
	sf::Sprite ButtonSprite;
};

