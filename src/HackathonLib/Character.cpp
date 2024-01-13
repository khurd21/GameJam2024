#include <HackathonLib/Character.hpp>
#include <HackathonLib/Type.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

Character::Character(float x, float y, float radius) {
    m_shape.setPosition(x, y);
    m_shape.setRadius(radius);
    m_shape.setFillColor(sf::Color::Green);
    m_shape.setOrigin(radius, radius);
}

void Character::update() {

}

void Character::handleInput(sf::RenderWindow& window) {
    // Handle user input for character movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        m_shape.move(0, -m_movementSpeed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        m_shape.move(0, m_movementSpeed);
    }
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
    return false;
}

void Character::handleCollision(const sf::FloatRect& shape, Type type) {
    if (type == Type::Wall) {
        if (getBoundingBox().intersects(shape)) {
            // Right
            if (m_shape.getPosition().x < shape.left) {
                m_shape.move(-m_movementSpeed, 0);
            }
            // Left
            else if (m_shape.getPosition().x + m_shape.getGlobalBounds().width > shape.left + shape.width) {
                m_shape.move(m_movementSpeed, 0);
            }
            // Top
            else if (m_shape.getPosition().y + m_shape.getGlobalBounds().height < shape.top + shape.height) {
                m_shape.move(0, -m_movementSpeed);
            }
            // Bottom
            else if (m_shape.getPosition().y > shape.top) {
                m_shape.move(0, m_movementSpeed);
            }

            // Left
            else if (m_shape.getPosition().x < shape.left + shape.width) {
            }
        }
    }
}