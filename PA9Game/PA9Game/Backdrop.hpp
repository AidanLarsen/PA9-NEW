#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Backdrop {
public:

	Backdrop() = default;
	explicit Backdrop(const std::string imgDirectory, const std::string imgDirectory2);
	void drawBackdrop(sf::RenderWindow& window);
	void animateBackdrop();
	void setPosition(float x, float y);
	void setScale(float x, float y);

private:

	sf::Texture backdropTexture;
	sf::Texture groundTexture;
	std::optional<sf::Sprite> bSprite;
	std::optional<sf::Sprite> gSprite;
	//sf::IntRect rect = sf::IntRect({ 0u, 0u }, { 1536u, 1024u });;
};