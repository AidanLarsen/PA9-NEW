#include "Animation.hpp"

void Animation::animate(Entity& entity, Direction direction, sf::Time& deltaTime)
{
	animationTimers[&entity] += deltaTime.asSeconds(); // the animation timer is updated using deltaTime
	if (animationTimers[&entity] < 0.2f) 
		return;
	animationTimers[&entity] = 0.0f;

	switch (direction)
	{
	case (Direction::Up): // this ended up not really getting used as we didn't make any jump animations
			if (entity.getRect()->position == entity.getSpriteVectors()[0])
			{
				entity.getRect()->position = entity.getSpriteVectors()[1];
			}
			else
			{
				entity.getRect()->position = sf::Vector2i{ 730u, 512u };
			}
			entity.getSprite()->setTextureRect(*entity.getRect());
		break;
	case (Direction::Left): // left animation triggered

			if (entity.getRect()->position == entity.getSpriteVectors()[3])
			{
				entity.getRect()->position = entity.getSpriteVectors()[2]; // this is the "starting position"
			}
			else
			{
				entity.getRect()->position = entity.getSpriteVectors()[3]; // this is the "ending position"
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