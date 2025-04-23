#include "Entity.hpp"

Entity::Entity(const std::string imgDirectory, float x, float y,
	unsigned rectX, unsigned rectY, unsigned width, unsigned height) {
	if (!pTexture.loadFromFile(imgDirectory)) {
		std::cerr << "Error\nCould not load image from directory.\n";
		return;
	}

	setRect(rectX, rectY, width, height);
	pSprite.emplace(pTexture, rect);
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

void Entity::setRect(unsigned rectX, unsigned rectY, unsigned width, unsigned height)
{
	this->rect.size.x = width;
	this->rect.size.y = height;
	this->rect.position.x = rectX;
	this->rect.position.y = rectY;
		//= ({0, 0}, { 273, 409 });
}

sf::IntRect* Entity::getRect()
{
	return &rect;
}

sf::Sprite* Entity::getSprite()
{
	return &pSprite.value();
}

void Entity::updateSprite()
{
	pSprite.emplace(pTexture, rect);
}
