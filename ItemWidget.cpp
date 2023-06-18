#include "ItemWidget.h"

ItemWidget::ItemWidget(Item& InItem, std::string InTexutrePath, sf::Font& InFont)
	: OwnItem(InItem), TexturePath(InTexutrePath), TextFont(InFont)
{
	//Allocate memory for textures
	ItemNameTextureWhite = std::make_shared<sf::Texture>();
	ItemDescriptionTextureWhite = std::make_shared<sf::Texture>();
	ItemLocationTextureWhite = std::make_shared<sf::Texture>();
	ItemQuantityTextureWhite = std::make_shared<sf::Texture>();
	ItemIDTextureWhite = std::make_shared<sf::Texture>();
	//Allocate memory for textures
	ItemNameTextureGrey = std::make_shared<sf::Texture>();
	ItemDescriptionTextureGrey = std::make_shared<sf::Texture>();
	ItemLocationTextureGrey = std::make_shared<sf::Texture>();
	ItemQuantityTextureGrey = std::make_shared<sf::Texture>();
	ItemIDTextureGrey = std::make_shared<sf::Texture>();
	//Load textures
	InitTextures();
	//Set Text font
	ItemNameText.setFont(TextFont);
	ItemDescriptionText.setFont(TextFont);
	ItemLocationText.setFont(TextFont);
	ItemQuantityText.setFont(TextFont);
	ItemIDText.setFont(TextFont);
	//Set Text color
	ItemNameText.setFillColor(sf::Color::Black);
	ItemDescriptionText.setFillColor(sf::Color::Black);
	ItemLocationText.setFillColor(sf::Color::Black);
	ItemQuantityText.setFillColor(sf::Color::Black);
	ItemIDText.setFillColor(sf::Color::Black);
	//Set Text size
	ItemNameText.setCharacterSize(15);
	ItemDescriptionText.setCharacterSize(15);
	ItemLocationText.setCharacterSize(15);
	ItemQuantityText.setCharacterSize(15);
	ItemIDText.setCharacterSize(15);

	initSprites();
	updateText();
	SetSpawnPosition(290,310);

}

void ItemWidget::Draw(sf::RenderTarget& Target) const
{
	//draw all properties sprites
	Target.draw(this->ItemNameSprite);
	Target.draw(this->ItemDescriptionSprite);
	Target.draw(this->ItemLocationSprite);
	Target.draw(this->ItemQuantitySprite);
	Target.draw(this->ItemIDSprite);
	//display all properties text
	Target.draw(this->ItemNameText);
	Target.draw(this->ItemDescriptionText);
	Target.draw(this->ItemLocationText);
	Target.draw(this->ItemQuantityText);
	Target.draw(this->ItemIDText);
}

void ItemWidget::initSprites()
{
	if (OwnItem.GetItemID() % 2 == 0)
	{
		ItemNameSprite.setTexture(*ItemNameTextureWhite);
		ItemDescriptionSprite.setTexture(*ItemDescriptionTextureWhite);
		ItemLocationSprite.setTexture(*ItemLocationTextureWhite);
		ItemQuantitySprite.setTexture(*ItemQuantityTextureWhite);
		ItemIDSprite.setTexture(*ItemIDTextureWhite);
	} 
	else
	{
		ItemNameSprite.setTexture(*ItemNameTextureGrey);
		ItemDescriptionSprite.setTexture(*ItemDescriptionTextureGrey);
		ItemLocationSprite.setTexture(*ItemLocationTextureGrey);
		ItemQuantitySprite.setTexture(*ItemQuantityTextureGrey);
		ItemIDSprite.setTexture(*ItemIDTextureGrey);
	}
}

void ItemWidget::updateText()
{
	ItemNameText.setString(OwnItem.GetItemName());
	ItemDescriptionText.setString(OwnItem.GetItemDescription());
	ItemLocationText.setString(OwnItem.GetItemLocation());
	ItemQuantityText.setString(std::to_string(OwnItem.GetItemQuantity()));
	ItemIDText.setString(std::to_string(OwnItem.GetItemID()));
}

void ItemWidget::SetSpawnPosition(int x, int y)
{
	//spawn pos of sprites
	ItemIDSprite.setPosition(x, y + OwnItem.GetItemID() * 50);
	ItemNameSprite.setPosition(x + 50, y + OwnItem.GetItemID() * 50);
	ItemDescriptionSprite.setPosition(x + 350, y + OwnItem.GetItemID() * 50);
	ItemLocationSprite.setPosition(x + 850, y + OwnItem.GetItemID() * 50);
	ItemQuantitySprite.setPosition(x + 1150, y + OwnItem.GetItemID() * 50);
	//spawn pos of text
	ItemIDText.setPosition(ItemIDSprite.getPosition().x + 10, ItemIDSprite.getPosition().y + 10);
	ItemNameText.setPosition(ItemNameSprite.getPosition().x + 10, ItemNameSprite.getPosition().y + 10);
	ItemDescriptionText.setPosition(ItemDescriptionSprite.getPosition().x + 10, ItemDescriptionSprite.getPosition().y + 10);
	ItemLocationText.setPosition(ItemLocationSprite.getPosition().x + 10, ItemLocationSprite.getPosition().y + 10);
	ItemQuantityText.setPosition(ItemQuantitySprite.getPosition().x + 10, ItemQuantitySprite.getPosition().y + 10);
}

void ItemWidget::InitTextures()
{
	//Load Textures White
	if (!ItemNameTextureWhite->loadFromFile("..\\SFML_inv\\Textures\\White\\Name.png"))
	{
		std::cout << "Failed to load texture(white) for Name value" << std::endl;
	}
	if (!ItemDescriptionTextureWhite->loadFromFile("..\\SFML_inv\\Textures\\White\\Description.png"))
	{
		std::cout << "Failed to load texture(white) for Description value" << std::endl;
	}
	if (!ItemLocationTextureWhite->loadFromFile("..\\SFML_inv\\Textures\\White\\Location.png"))
	{
		std::cout << "Failed to load texture(white) for Location value" << std::endl;
	}
	if (!ItemQuantityTextureWhite->loadFromFile("..\\SFML_inv\\Textures\\White\\Quantity.png"))
	{
		std::cout << "Failed to load texture(white) for Quantity value" << std::endl;
	}
	if (!ItemIDTextureWhite->loadFromFile("..\\SFML_inv\\Textures\\White\\ID.png"))
	{
		std::cout << "Failed to load texture(white) for ID value" << std::endl;
	}
	//Load Textures Grey
	if (!ItemNameTextureGrey->loadFromFile("..\\SFML_inv\\Textures\\Grey\\Name.png"))
	{
		std::cout << "Failed to load texture(grey) for Name value" << std::endl;
	}
	if (!ItemDescriptionTextureGrey->loadFromFile("..\\SFML_inv\\Textures\\Grey\\Description.png"))
	{
		std::cout << "Failed to load texture(grey) for Description value" << std::endl;
	}
	if (!ItemLocationTextureGrey->loadFromFile("..\\SFML_inv\\Textures\\Grey\\Location.png"))
	{
		std::cout << "Failed to load texture(grey) for Location value" << std::endl;
	}
	if (!ItemQuantityTextureGrey->loadFromFile("..\\SFML_inv\\Textures\\Grey\\Quantity.png"))
	{
		std::cout << "Failed to load texture(grey) for Quantity value" << std::endl;
	}
	if (!ItemIDTextureGrey->loadFromFile("..\\SFML_inv\\Textures\\Grey\\ID.png"))
	{
		std::cout << "Failed to load texture(grey) for ID value" << std::endl;
	}
}

ItemWidget::WidgetState ItemWidget::UpdateWidgetState(const sf::Vector2f& Point)
{
	if (ItemNameSprite.getGlobalBounds().contains(Point))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			return WidgetState::Btn_Active_Name;
		}
		return WidgetState::Btn_Hover_Name;
	}
	else if (ItemDescriptionSprite.getGlobalBounds().contains(Point))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			return WidgetState::Btn_Active_Description;
		}
		return WidgetState::Btn_Hover_Description;
	}
	else if (ItemLocationSprite.getGlobalBounds().contains(Point))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			return WidgetState::Btn_Active_Location;
		}
		return WidgetState::Btn_Hover_Location;
	}
	else if (ItemQuantitySprite.getGlobalBounds().contains(Point))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			return WidgetState::Btn_Active_Quantity;
		}
		return WidgetState::Btn_Hover_Quantity;
	}
	else if (ItemIDSprite.getGlobalBounds().contains(Point))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			return WidgetState::Btn_Active_ID;
		}
		return WidgetState::Btn_Hover_ID;
	}
	else
	{
		return WidgetState::Idle;
	}
}

