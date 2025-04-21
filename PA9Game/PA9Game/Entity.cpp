#include "Entity.hpp"

Entity::Entity(const std::string imgDirectory, float x, float y) {
	if (!pTexture.loadFromFile(imgDirectory)) {
		std::cerr << "Error\nCould not load image from directory.\n";
		return;
	}

	pSprite.emplace(pTexture); 
	pSprite->setPosition({ x, y });
	startingPoint = { x, y };
}

void Entity::drawEntity(sf::RenderWindow& window)
{
	if (pSprite){

		window.draw(*pSprite);

	}
}

void Entity::setPosition(float x, float y)
{
	if (pSprite) {

		pSprite->setPosition({x, y});

	}
}

void Entity::setScale(float x, float y)
{
	if (pSprite){

		pSprite->setScale({x, y});

	}
}

