#include "GUI.h"

GUI::GUI(Inventory& InInvetory)
	: ItemMatrix(InInvetory), PageSwitcher(ItemMatrix, 10), AddItem(ItemMatrix)

{
	BackGroundTexture.loadFromFile("..\\SFML_inv\\Textures\\BackGround.png");
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
			Handler.handleInput(Window,WindowEvent, ItemMatrix.GetWidgets(), PageSwitcher.GetStartIndex(), std::min(PageSwitcher.GetStartIndex() + 10, ItemMatrix.GetSize()));
			AddItem.Click(Window);

			if (PageSwitcher.Click(Window))
			{
				ItemMatrix.SetStartIndex(PageSwitcher.GetStartIndex());
			}

			if(AddItem.Click(Window))
			{
				InInventory.AddItem();
				DataHandler.addItemToFile();
				ItemMatrix.UpdateWidgetArray(InInventory);
			}
		}

		Window.clear();
		Window.draw(BackGroundSprite);
		ItemMatrix.draw(Window);
		PageSwitcher.Draw(Window);
		AddItem.Draw(Window);
		Window.display();
	}

}
