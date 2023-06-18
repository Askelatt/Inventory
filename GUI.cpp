#include "GUI.h"

GUI::GUI(Inventory& InInvetory)
	: ItemMatrix(InInvetory)

{
	BackGroundTexture.loadFromFile("..\\SFML_inv\\Textures\\logo.png");
	BackGroundSprite.setTexture(BackGroundTexture);
}

void GUI::runApp(Inventory& InInventory)
{
	sf::RenderWindow Window(sf::VideoMode(1920, 1080), "Inventory");
	Window.setFramerateLimit(30);

	while (Window.isOpen())
	{
		while (Window.pollEvent(WindowEvent))
		{
			if (WindowEvent.type == sf::Event::Closed)
			{
				Window.close();
				DataHandler.saveInventoryToFile(InInventory.GetInventory());
			}
			Handler.handleInput(Window,WindowEvent, ItemMatrix.GetWidgets());
		}

		Window.clear();
		Window.draw(BackGroundSprite);
		ItemMatrix.draw(Window);
		Window.display();
	}

}
