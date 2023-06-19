#pragma once
#include "SFML\Graphics.hpp"
#include "Item.h"
#include <iostream>

class ItemWidget
{

public:

	//Constructor
	ItemWidget(Item& InItem, std::string InTexutrePath, sf::Font& InFont);

	//struct to trach widget state
	enum struct WidgetState { Idle, Btn_Hover_Name, Btn_Hover_Description, Btn_Hover_Location, Btn_Hover_Quantity, Btn_Hover_ID, Btn_Active_Name, Btn_Active_Description, Btn_Active_Location, Btn_Active_Quantity, Btn_Active_ID };
	//Item to represent
	Item& OwnItem;

	void Draw(sf::RenderTarget& Target) const;

	void initSprites();
	void updateText();
	void SetSpawnPosition(int x, int y);
	void InitTextures();
	const sf::Vector2f GetPosition() const;
	WidgetState UpdateWidgetState(sf::RenderWindow& InWindow);

private:

	//Texture path
	std::string TexturePath;
	//Textures for properties 
	std::shared_ptr<sf::Texture> ItemNameTextureWhite;
	std::shared_ptr<sf::Texture> ItemDescriptionTextureWhite;
	std::shared_ptr<sf::Texture> ItemLocationTextureWhite;
	std::shared_ptr<sf::Texture> ItemQuantityTextureWhite;
	std::shared_ptr<sf::Texture> ItemIDTextureWhite;
	//Textures for properties 
	std::shared_ptr<sf::Texture> ItemNameTextureGrey;
	std::shared_ptr<sf::Texture> ItemDescriptionTextureGrey;
	std::shared_ptr<sf::Texture> ItemLocationTextureGrey;
	std::shared_ptr<sf::Texture> ItemQuantityTextureGrey;
	std::shared_ptr<sf::Texture> ItemIDTextureGrey;
	//Sprites for properties
	sf::Sprite ItemNameSprite;
	sf::Sprite ItemDescriptionSprite;
	sf::Sprite ItemLocationSprite;
	sf::Sprite ItemQuantitySprite;
	sf::Sprite ItemIDSprite;
	//TextVariable for properties
	sf::Text ItemNameText;
	sf::Text ItemDescriptionText;
	sf::Text ItemLocationText;
	sf::Text ItemQuantityText;
	sf::Text ItemIDText;
	//Font for text
	sf::Font& TextFont;
	//State of Widget
	WidgetState WidgState = WidgetState::Idle;

};

