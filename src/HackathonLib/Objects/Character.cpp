#include <HackathonLib/Objects/Character.hpp>
#include <HackathonLib/Type.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

Character::Character(float x, float y, float radius) {
    m_shape.setPosition(x, y);
    m_shape.setRadius(radius);
    m_shape.setFillColor(sf::Color::Green);
    m_shape.setOrigin(radius, radius);
}

void Character::update(float deltaTime) {

}

void Character::handleInput(sf::RenderWindow& window) {
    // Handle user input for character movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        m_shape.move(-m_movementSpeed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        m_shape.move(m_movementSpeed, 0);
    }
}

sf::FloatRect Character::getBoundingBox() const {
    return m_shape.getGlobalBounds();
}

void Character::draw(sf::RenderWindow& window) const {
    window.draw(m_shape);
}

bool Character::isCollision(const sf::FloatRect& shape) const {
    return getBoundingBox().intersects(shape);
}

void Character::handleCollision(const sf::FloatRect& shape, Type type) {
    if (getBoundingBox().intersects(shape)) {
        if (Type::Cloud == type) {
            // Change to the frozen sprite
            // Freezing sound
        }
        else if (Type::Enemy == type) {
            // Character blinks
            // Hit sound
        }
        else if (Type::PowerUp == type) {
            // 
        }
    }
}