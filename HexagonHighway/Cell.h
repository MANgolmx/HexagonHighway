#pragma once
#include <SFML/Graphics.hpp>

enum Directions { STOP ,UP, RIGHT, DOWN, LEFT};

class Cell
{
protected:
	sf::Texture* square_texture;
	sf::Sprite square_sprite;

	sf::Vector2f position;
	sf::Vector2f mainPosition;
	Directions direction;

public:
	Cell();
	Cell(sf::Texture& tx);
	~Cell();

	sf::Vector2f GetPosition();
	void SetPosition(Cell cell);
	void SetPosition(Cell* cell);
	void SetPosition(sf::Vector2f pos);
	void SetPosition(int x, int y);

	virtual void SetCellSprite(std::string path);
	virtual void SetCellSprite(sf::Texture& tx);

	void SetMainPosition(sf::Vector2f pos);
	void SetMainPosition(int x, int y);
	sf::Vector2f GetMainPosition();

	Directions GetDirection();
	void SetDirection(Directions dir);

	void Rotation();

	virtual void Draw(sf::RenderWindow& win);

	sf::Texture* GetCellTexture();
	sf::Sprite GetCellSprite();
};