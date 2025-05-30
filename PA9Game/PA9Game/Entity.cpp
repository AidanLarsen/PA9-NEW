#include "Entity.hpp"

Entity::Entity(const sf::Texture& texture, float x, float y,
	unsigned rectX, unsigned rectY, unsigned width, unsigned height) {
	
	pTexture = &texture;

	setRect(rectX, rectY, width, height);
	pSprite.emplace(*pTexture, rect);
	pSprite->setPosition({ x, y });
	startingPoint = { x, y };
}

void Entity::drawEntity(sf::RenderWindow& window)
{
	if (pSprite) {

		window.draw(*pSprite);

	}
}

// getters and setters for the entity class, 
void Entity::setPosition(float x, float y)
{
	if (pSprite) {

		pSprite->setPosition({ x, y });

	}
}

void Entity::setScale(float x, float y)
{
	if (pSprite) {

		pSprite->setScale({ x, y });

	}
}

void Entity::setRect(unsigned rectX, unsigned rectY, unsigned width, unsigned height)
{
	this->rect.size.x = width;
	this->rect.size.y = height;
	this->rect.position.x = rectX;
	this->rect.position.y = rectY;
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
	pSprite.emplace(*pTexture, rect);
}

sf::Vector2i* Entity::getSpriteVectors()
{
	return spriteVectors;
}
