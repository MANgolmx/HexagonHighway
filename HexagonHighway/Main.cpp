#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"
#include "Assistant.h"
#include "Car.h"

using namespace sf;

int main()
{
	srand(time(0));
	const int roadSize = 12;
	const int decorationSize = 1;

#pragma region INITIALIZATION

	int window_width = 1212, window_height = 808;

	Clock clock;

	RenderWindow window(VideoMode(window_width, window_height), "RoadWay");

	NonDrivableCell chosen("resources\\cells\\chosen.png");

	DrivableCell roads[roadSize];
	SetDrivablePath(roads, roadSize, 4, 4, 4, 0);

	NonDrivableCell decorations[decorationSize];
	SetNonDrivablePath(decorations, decorationSize, 0, 1, 0);

	Car car("resources\\cars\\car_2.png");
	car.position = { 535,436 };
	car.mainPosition = { 0,1 };

	ReadMainPositions(roadSize, roads, decorationSize, decorations);
	SetPositions(roadSize, roads, decorationSize, decorations);

#pragma endregion

	while (window.isOpen()) //���� ���������
	{
		Event event;
		while (window.pollEvent(event)) //���� �������
		{
			switch (event.type)
			{
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

	return 0;
}