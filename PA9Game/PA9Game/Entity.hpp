#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <utility>

class Entity {
public:

	Entity() = default;

	Entity(const std::string imgDirectory, float x, float y);

	void drawEntity(sf::RenderWindow& window);

	void setPosition(float x, float y);

	void setScale(float x, float y);

protected:

	sf::Texture pTexture;
	std::optional<sf::Sprite> pSprite;
	std::pair<float, float> startingPoint; //variable to hold the starting position

};