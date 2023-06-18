#pragma once
#include "InventoryMatrix.h"
#include "Inventory.h"
#include "HandleInput.h"
#include "XMLDataHandler.h"

class GUI
{
private:

	InventoryMatrix ItemMatrix;
	InputHandler Handler;
	XMLDataHandler DataHandler;

	sf::Event WindowEvent;

	sf::Texture BackGroundTexture;
	sf::Sprite BackGroundSprite;
public:

	GUI(Inventory& InInvetory);

	void runApp(Inventory& InInventory);

};

