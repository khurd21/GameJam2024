#include <HackathonLib/Objects/Character.hpp>
#include <HackathonLib/Type.hpp>
#include <HackathonLib/PixelPerfectDetection.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

Character::Character(float x, float y, float radius) {
    m_texture.loadFromFile("./resources/images/person.png");
    m_shape.setTexture(&m_texture);
    m_shape.setPosition(x, y);
    m_shape.setRadius(radius);
    m_shape.setOrigin(radius, radius);

    m_collisionShape.setSize({150, 5});
    m_collisionShape.setRotation(-18);
    m_collisionShape.setFillColor(sf::Color::Transparent);
}

void Character::update(float deltaTime) {
    const auto& position{ m_shape.getPosition() };
    m_collisionShape.setPosition(position.x - m_collisionShape.getGlobalBounds().width / 2, position.y + 45);
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
    return m_collisionShape.getTransform().transformRect(m_collisionShape.getLocalBounds());
}

void Character::draw(sf::RenderWindow& window) const {
    window.draw(m_shape);
    window.draw(m_collisionShape);
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
    }
}