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
    m_originalColor = m_shape.getFillColor();

    m_coin1Buffer.loadFromFile("resources/sounds/collect-coin.ogg");
    m_coin2Buffer.loadFromFile("resources/sounds/collect-coin2.ogg");
    m_crowBuffer.loadFromFile("resources/sounds/crow.ogg");
    m_freezingBuffer.loadFromFile("resources/sounds/crack-and-crunch.ogg");
    m_clockBuffer.loadFromFile("resources/sounds/clock1.ogg");
    m_coin1Sound.setBuffer(m_coin2Buffer);
    m_coin2Sound.setBuffer(m_coin1Buffer);
    m_crowSound.setBuffer(m_crowBuffer);
    m_freezingSound.setBuffer(m_freezingBuffer);
    m_clockSound.setBuffer(m_clockBuffer);
}

void Character::update(float deltaTime) {
    if (m_isFrozen) {
        m_freezeTimer -= deltaTime;
        if (m_freezeTimer <= 0.0f) {
            m_isFrozen = false;  // Unfreeze the character when the timer expires
        }
        m_shape.setFillColor(sf::Color::Blue);
    }
    else {
        m_shape.setFillColor(m_originalColor);
    }
    const auto& position{ m_shape.getPosition() };
    m_collisionShape.setPosition(position.x - m_collisionShape.getGlobalBounds().width / 2, position.y + 45);
}

void Character::handleInput(sf::RenderWindow& window) {
    if (m_isFrozen) {
        return;
    }
    // Handle user input for character movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        m_shape.move(-m_movementSpeed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        m_shape.move(m_movementSpeed, 0);
    }

    // Perform boundary checking
    const auto& position = m_shape.getPosition();
    const auto& size = m_shape.getScale();
    const auto& windowSize = window.getSize();

    // Ensure the character stays within the left boundary
    if (position.x - size.x / 2 < 0) {
        m_shape.setPosition(size.x / 2, position.y);
    }

    // Ensure the character stays within the right boundary (2/3 of the screen width)
    float rightBoundary = (2.0f / 3.0f) * windowSize.x;
    if (position.x + size.x / 2 > rightBoundary) {
        m_shape.setPosition(rightBoundary - size.x / 2, position.y);
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
            if (m_freezingSound.getStatus() != sf::SoundSource::Status::Playing) {
                m_freezingSound.play();
            }
            freeze();
        }
        else if (Type::Coin1 == type) {
            if (m_coin1Sound.getStatus() != sf::SoundSource::Status::Playing) {
                m_coin1Sound.play();
            }
        }
        else if (Type::Coin2 == type) {
            if (m_coin2Sound.getStatus() != sf::SoundSource::Status::Playing) {
                m_coin2Sound.play();
            }
        }
        else if (Type::Bird == type) {
            if (m_crowSound.getStatus() != sf::SoundSource::Status::Playing) {
                m_crowSound.play();
            }
        }
        else if (Type::Clock10 == type || Type::Clock5 == type) {
            if (m_clockSound.getStatus() != sf::SoundSource::Status::Playing) {
                m_clockSound.play();
            }
        }
    }
}

bool Character::isFrozen() const {
    return m_isFrozen;
}

void Character::freeze() {
    m_isFrozen = true;
    m_freezeTimer = m_freezeDuration;
}

void Character::unfreeze() {
    m_isFrozen = 0.0f;
}