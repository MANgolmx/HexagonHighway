#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"
#include "Assistant.h"
#include "Car.h"
#include "FText.h"
#include "Button.h"
#include "Level.h"
#include "Logo.h"
#include "Background.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Settings.h"

using namespace sf;

int settings(sf::RenderWindow& window)
{
	srand(time(0));

#pragma region INITIALIZATION

	Background menu("resources\\menu.png");

	float f1 = 1920 / 2 - window.getSize().x / 2;
	float f2 = 1080 / 2 - window.getSize().y / 2;
	menu.SetPosition({ -f1,-f2 });

	FText txt_volume_minus(" ", 0, "resources\\fonts\\pixeltime\\PixelTimes.ttf");
	Button bt_volume_minus(txt_volume_minus, "resources\\buttons\\button_volume.png", { 0,0 });

	f1 = window.getSize().x / 2 - bt_volume_minus.GetTexture().getSize().x - 100;
	f2 = window.getSize().y / 4 - bt_volume_minus.GetTexture().getSize().y;
	bt_volume_minus.SetPosition({ f1,f2 });

	bt_volume_minus.Mirrored(180);

	FText txt_volume_plus(" ", 0, "resources\\fonts\\pixeltime\\PixelTimes.ttf");
	Button bt_volume_plus(txt_volume_plus, "resources\\buttons\\button_volume.png", { 0,0 });

	f1 = window.getSize().x / 2 - bt_volume_plus.GetTexture().getSize().x + 100;
	f2 = window.getSize().y / 4 - bt_volume_plus.GetTexture().getSize().y;
	bt_volume_plus.SetPosition({ f1,f2 });

	window.setFramerateLimit(60);

	bool inSettings = true;

#pragma endregion

	while (inSettings) //���� ���������
	{
		Event event;
		while (window.pollEvent(event)) //���� �������
		{
			switch (event.type)
			{
			case Event::Closed:
				return 1;
			case Event::KeyPressed:
				if (event.key.code == Keyboard::Escape)
					inSettings = false;
				break;
			case Event::MouseButtonPressed:
				if (Mouse::isButtonPressed(Mouse::Button::Left)) //����� ������ ����
				{

				}
				break;
			case Event::Resized:
				Vector2f windowSize = Vector2f(event.size.width, event.size.height);
				window.setView(View(Vector2f(windowSize.x / 2.f,
					windowSize.y / 2.f), Vector2f(windowSize)));

				f1 = (1920 / 2 - window.getSize().x / 2);
				f2 = (1080 / 2 - window.getSize().y / 2);
				menu.SetPosition({ -f1,-f2 });

				f1 = window.getSize().x / 2 - bt_volume_plus.GetTexture().getSize().x + 100;
				f2 = window.getSize().y / 4 - bt_volume_plus.GetTexture().getSize().y;
				bt_volume_plus.SetPosition({ f1,f2 });

				f1 = window.getSize().x / 2 - bt_volume_minus.GetTexture().getSize().x - 100;
				f2 = window.getSize().y / 4 - bt_volume_minus.GetTexture().getSize().y;
				bt_volume_minus.SetPosition({ f1,f2 });
				break;
			}
		}

		window.draw(menu.GetSprite());
		bt_volume_minus.Draw(window);
		bt_volume_plus.Draw(window);
		window.display();
	}

	return 0;
}