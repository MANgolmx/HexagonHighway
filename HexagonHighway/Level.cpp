#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"
#include "Assistant.h"
#include "Car.h"
#include "Level.h"

using namespace sf;

void levelStart(RenderWindow& window)
{

#pragma region INITIALIZATION

	int roadSize = 12;
	int decorationSize = 1;

	int window_width = 1212, window_height = 808;

	Clock clock;

	NonDrivableCell chosen("resources\\cells\\chosen.png");

	DrivableCell* roads = new DrivableCell[roadSize];
	SetDrivablePath(roads, roadSize, 4, 4, 4, 0);

	NonDrivableCell* decorations = new NonDrivableCell[decorationSize];
	SetNonDrivablePath(decorations, decorationSize, 0, 1, 0);

	Car car("resources\\cars\\car_1.png");

	ReadMainPositions(roadSize, roads, decorationSize, decorations);
	SetPositions(roadSize, roads, decorationSize, decorations);

	window.setFramerateLimit(60);

#pragma endregion

	while (window.isOpen()) //���� ����
	{
		Event event;
		while (window.pollEvent(event)) //���� �������
		{
			switch (event.type)
			{
			// TODO: �������� ����������������� �������� ��� ��������� ����
			case Event::Closed:
				window.close();
				break;
			case Event::MouseButtonPressed: //������ ������ ����
				if (Mouse::isButtonPressed(Mouse::Button::Left)) //����� ������ ����
				{
					SetIsChosen(false, roadSize, roads);
					for (int i = 0; i < roadSize; i++)
						if (isBelong(Mouse::getPosition(window), roads[i]))
							roads[i].Rotation();
				}
				if (Mouse::isButtonPressed(Mouse::Button::Right)) //������ ������ ����
					CheckSwap(roadSize, roads, window);
				break;
			}
		}

		car.Move(clock.restart(), roads, roadSize, decorations, decorationSize);

		window.clear({ 181, 230, 29, 255 });
		DrawCells(window, roads, chosen, roadSize, decorations, decorationSize);
		car.Draw(window);
		window.display();
	}
}