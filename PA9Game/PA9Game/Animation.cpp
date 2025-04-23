#include "Animation.hpp"

//EntityPosition pos;

void Animation::animate(Entity& entity, Direction direction, sf::Time& deltaTime)
{
	animationTimers[&entity] += deltaTime.asSeconds();
	if (animationTimers[&entity] < 0.2f)
		return;
	animationTimers[&entity] = 0.0f;

	switch (direction)
	{
	case (Direction::Up):
			if (entity.getRect()->position == entity.getSpriteVectors()[0])//sf::Vector2i{ 730u, 512u })
			{
				entity.getRect()->position = entity.getSpriteVectors()[1];
			}
			else
			{
				entity.getRect()->position = sf::Vector2i{ 730u, 512u };
			}
			entity.getSprite()->setTextureRect(*entity.getRect());
		break;
	case (Direction::Left):
			if (entity.getRect()->position == entity.getSpriteVectors()[3])
			{
				entity.getRect()->position = entity.getSpriteVectors()[2];
			}
			else
			{
				entity.getRect()->position = entity.getSpriteVectors()[3];
			}

			entity.getSprite()->setTextureRect(*entity.getRect());
		break;
	case (Direction::Right):
			if (entity.getRect()->position == entity.getSpriteVectors()[1])
			{
				entity.getRect()->position = entity.getSpriteVectors()[0];
			}
			else
			{
				entity.getRect()->position = entity.getSpriteVectors()[1];
			}
			entity.getSprite()->setTextureRect(*entity.getRect());
		break;
	}
}