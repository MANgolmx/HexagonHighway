#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"
#include "Assistant.h"

using namespace sf;

int main()
{
	srand(time(0));
	const int N = 12;

#pragma region INITIALIZATION

	int window_width = 1212, window_height = 808;

	RenderWindow window(VideoMode(window_width, window_height), "RoadWay");

	DrivableCell cell[N];
	SetPath(cell, N, 6, 6, 0, 0);

	NonDrivableCell chosen;
	chosen.SetCellSprite("resources\\cells\\chosen.png");

	ReadMainPositions(N, cell);
	SetPositions(N, cell);

#pragma endregion

		//TODO: �������� ��������� ������ ����� ������� �����

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
					SetIsChosen(false, N, cell);
					for (int i = 0; i < N; i++)
						if (isBelong(Mouse::getPosition(window), cell[i]))
							cell[i].Rotation();
				}
				if (Mouse::isButtonPressed(Mouse::Button::Right)) //������ ������ ����
					CheckSwap(N, cell, window);
				break;
			}
		}
		
		window.clear();
		DrawCells(window, cell, chosen, N);
		window.display();
	}

	return 0;
}