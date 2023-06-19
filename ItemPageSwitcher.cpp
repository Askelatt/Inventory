#include "ItemPageSwitcher.h"

ItemPageSwitcher::ItemPageSwitcher(InventoryMatrix& InMatrix, int InItemsPerPage)
	: ItemMatrix(InMatrix), ItemsPerPage(InItemsPerPage), StartIndex(0)
{

	ButtonTextureArrowLeft = std::make_shared<sf::Texture>();
	ButtonTextureArrowRight = std::make_shared<sf::Texture>();

	if (!ButtonTextureArrowLeft->loadFromFile("..\\SFML_inv\\Textures\\ItemPageSwitcherArrows\\Left.png"))
	{
		std::cout << "Failed to load texture for arrow Left" << std::endl;
	}
	
	if (!ButtonTextureArrowRight->loadFromFile("..\\SFML_inv\\Textures\\ItemPageSwitcherArrows\\Right.png"))
	{
		std::cout << "Failed to load texture for arrow Right" << std::endl;
	}

	ButtonSpriteArrowLeft.setTexture(*ButtonTextureArrowLeft);
	ButtonSpriteArrowRight.setTexture(*ButtonTextureArrowRight);

	ButtonSpriteArrowLeft.setPosition(InMatrix.GetWidgets()[0].GetPosition().x + 1500, InMatrix.GetWidgets()[0].GetPosition().y - 45);
	ButtonSpriteArrowRight.setPosition(InMatrix.GetWidgets()[0].GetPosition().x + 1530, InMatrix.GetWidgets()[0].GetPosition().y - 45);
}

bool ItemPageSwitcher::Click(sf::RenderWindow& InWindow)
{
	sf::Vector2i PixelPos = sf::Mouse::getPosition(InWindow);
	sf::Vector2f WorldPos = InWindow.mapPixelToCoords(PixelPos);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
	{
		if (ButtonSpriteArrowLeft.getGlobalBounds().contains(WorldPos))
		{
			StartIndex -= ItemsPerPage;
			if (StartIndex < 0)
			{
				StartIndex = StartIndex - ItemsPerPage < 0 ? ItemMatrix.GetWidgets().size() - ItemsPerPage : StartIndex - ItemsPerPage;
				return true;
			}
			return true;
		}
	}
	
if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
	if (ButtonSpriteArrowRight.getGlobalBounds().contains(WorldPos))
		{
			StartIndex += ItemsPerPage;
			if (StartIndex >= ItemMatrix.GetWidgets().size())
			{
				StartIndex = StartIndex + ItemsPerPage >= ItemMatrix.GetWidgets().size() ? 0 : StartIndex + ItemsPerPage;
				return true;
			}
			return true;
		}
	}
	return false;
}

void ItemPageSwitcher::Draw(sf::RenderTarget& Target) const
{
	Target.draw(ButtonSpriteArrowLeft);
	Target.draw(ButtonSpriteArrowRight);
}

int ItemPageSwitcher::GetStartIndex()
{
	return StartIndex;
}
