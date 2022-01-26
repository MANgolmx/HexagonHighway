#include "DrivableCell.h"

DrivableCell::DrivableCell()
{
	type = undefiened;
}

DrivableCell::DrivableCell(std::string path)
{
	type = undefiened;

	if (!square_texture.loadFromFile(path)) {
		std::cout << "[ERROR OCURRED] Can not open Cell.png" << std::endl;
		exit(1);
	}

	square_sprite.setTexture(square_texture);
	square_sprite.setPosition(position.x, position.y);
}

DrivableCell::~DrivableCell()
{

}

types DrivableCell::GetType()
{
	return type;
}

void DrivableCell::SetType(int& straight, int& turned, int& threeway, int& fourway)
{
	std::string path;

	int a = rand() % 4;
	switch (a) {
	case 0: Cell::direction = up; break;
	case 1: Cell::direction = right; break;
	case 2: Cell::direction = down; break;
	case 3: Cell::direction = left; break;
	}
	Rotation();
	
	a = rand() % 2;

	switch (a) {
	case 0: goto straightRand;
	case 1: goto turnedRand;
	}

	straightRand:
		if (straight > 0)
		{
			type = types::straight;

			int tmp = rand() % 25;
			switch (tmp) {
			case 4: case 8: case 12: case 22:
			case 0: path = "resources\\cells\\straight\\straight_flowers_1.png";		 break;
			case 5: case 9: case 13: case 23:
			case 1: path = "resources\\cells\\straight\\straight_flowers_2.png";		 break;
			case 6: case 10: case 20:
			case 2: path = "resources\\cells\\straight\\straight_flowers_3.png"; 		 break;
			case 7: case 11: case 21:
			case 3: path = "resources\\cells\\straight\\straight_flowers_4.png";	 break;
			case 14: path = "resources\\cells\\straight\\straight_trashbin_1.png";	 break;
			case 15: path = "resources\\cells\\straight\\straight_trashbin_2.png";	 break;
			case 16: path = "resources\\cells\\straight\\straight_trashbin_3.png";	 break;
			case 17: path = "resources\\cells\\straight\\straight_trashbin_4.png";	 break;
			case 18: path = "resources\\cells\\straight\\straight_trashbin_5.png";	 break;
			case 19: path = "resources\\cells\\straight\\straight_trashbin_6.png";	 break;
			case 24: path = "resources\\cells\\straight\\straight_busstop_1.png";	 break;
			}

			if (!square_texture.loadFromFile(path)) {
				std::cout << "[ERROR OCURRED] Can not open Straight.png" << std::endl;
				exit(1);
			}

			square_sprite.setTexture(square_texture);

			straight--;
			return;
		}

	turnedRand:
		if (turned > 0)
		{
			type = types::turned;

			int tmp = rand() % 6;
			switch (tmp) {
			case 0: path = "resources\\cells\\turned\\turned_flowers_1.png"; break;
			case 1: path = "resources\\cells\\turned\\turned_flowers_2.png"; break;
			case 2: path = "resources\\cells\\turned\\turned_flowers_3.png"; break;
			case 3: path = "resources\\cells\\turned\\turned_flowers_4.png"; break;
			case 4: path = "resources\\cells\\turned\\turned_busstop_1.png"; break;
			case 5: path = "resources\\cells\\turned\\turned_busstop_2.png"; break;
			}

			if (!square_texture.loadFromFile(path)) {
				std::cout << "[ERROR OCURRED] Can not open Turned.png" << std::endl;
				exit(1);
			}

			square_sprite.setTexture(square_texture);

			turned--;
			return;
		}

	goto straightRand;
}