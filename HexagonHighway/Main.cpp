#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "DrivableCell.h"
#include "NonDrivableCell.h"
#include "assistant.h"

using namespace sf;

int main()
{
	srand(time(0));
	const int N = 12;

#pragma region INITIALIZATION

	int window_width = 1212, window_height = 808;

	RenderWindow window(VideoMode(window_width, window_height), "RoadWay");

	DrivableCell cell[N];
	SetPath(cell, N, 11, 1, 0, 0);

		for (int i = 0; i < N - 1; i++)
			cell[i].SetPosition(i * 101, 0);
		cell[11].SetPosition(0, 101);

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
					for (int i = 0; i < N; i++)
						if (isBelong(Mouse::getPosition(window), cell[i]))
							cell[i].Rotation();
				if (Mouse::isButtonPressed(Mouse::Button::Right)) //������ ������ ����
				{
					int count = 0;
					int ind1 = -1, ind2 = -1;
					for (int i = 0; i < N; i++)
						if (isBelong(Mouse::getPosition(window), cell[i]))
							cell[i].SetChose(true);
					for (int i = 0; i < N; i++)
						if (cell[i].ifChosen())
						{
							if (count == 0) ind1 = i;
							else ind2 = i;
							count++;
						}
					if (count == 2)
					{
						DrivableCell::Swap(cell[ind1], cell[ind2]);
						for (int i = 0; i < N; i++)
							cell[i].SetChose(false);
					}
				}
				break;
			}
		}


		window.clear();
		for (int i = 0; i < N; i++)
			window.draw(cell[i].GetCellSprite());
		window.display();
	}

	return 0;
}