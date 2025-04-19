#include <iostream>
#include <SFML/Graphics.hpp>


class Entity {
public:

	Entity() = default;
	explicit Entity(const std::string imgDirectory);
	void drawEntity(sf::RenderWindow& window);
	void setPosition(float x, float y);
	void setScale(float x, float y);

private:

	sf::Texture pTexture;
	std::optional<sf::Sprite> pSprite;

};