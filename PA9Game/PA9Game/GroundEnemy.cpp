#include "GroundEnemy.hpp"


// updates the position of the enemy
void GroundEnemy::update() {

    if (!pSprite.has_value()) {
        return;
    }

    sf::Vector2f currentPos = pSprite->getPosition();

    if (currentPos.x >= rightBound) velocity.x = -.1f;

    if (currentPos.x <= leftBound)  velocity.x = .1f;

    pSprite->move(velocity);
}