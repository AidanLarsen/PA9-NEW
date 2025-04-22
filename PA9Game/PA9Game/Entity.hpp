#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <utility>
class Entity {
public:

	Entity() = default;
	explicit Entity(const std::string imgDirectory, float x, float y);
	void drawEntity(sf::RenderWindow& window);
	void setPosition(float x, float y);
	void setScale(float x, float y);

	sf::IntRect* getRect(); // animation stuff
	sf::Sprite* getSprite();
	void updateSprite(); // animation stuff
protected:

	sf::Texture pTexture;
	std::optional<sf::Sprite> pSprite;
	sf::IntRect rect = sf::IntRect({ 0, 0 }, { 273, 409 });
	std::pair<float, float> startingPoint; //variable to hold the starting position

};