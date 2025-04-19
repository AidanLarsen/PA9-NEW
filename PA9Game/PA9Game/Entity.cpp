#include "Entity.hpp"

Entity::Entity(const std::string imgDirectory)
{
	if (!pTexture.loadFromFile(imgDirectory)){

		std::cerr << "Error\nCould not load image from directory.\n";

	}
	else{

		pSprite.emplace(pTexture);

	}
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

