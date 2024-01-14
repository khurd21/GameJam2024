#include <HackathonLib/Objects/Token.hpp>
#include <HackathonLib/Type.hpp>

#include <SFML/Graphics.hpp>

#include <random>
#include <string>
#include <iostream>

namespace {

std::random_device dev;
std::mt19937 rng(dev());

} // namespace

Token::Token(const sf::Texture& texture, float movementSpeed)
    : m_movementSpeed(movementSpeed), m_defaultMovementSpeed(movementSpeed) {

    m_shape.setTexture(&texture);
    m_shape.setRadius(50);
    m_originalColor = m_shape.getFillColor();

    m_collisionShape.setFillColor(sf::Color::Transparent);
    m_collisionShape.setRadius(10);
    setRandomPosition();
}

void Token::update(float deltaTime) {
    const auto& position{ m_shape.getPosition() };
    m_collisionShape.setPosition(position.x + 35, position.y + 55);
    if (!m_isLaunched) {
        std::uniform_int_distribution<std::mt19937::result_type> dist(1, 500);
        m_isLaunched = dist(rng) == 297;
    }
    else if (m_isFading) {
        m_fadeTimer -= deltaTime;
        if (m_fadeTimer <= 0.0f) {
            m_readyForRemoval = true;
        }
        else {
            const auto alpha{ static_cast<int>(255 * (m_fadeTimer / m_fadeDuration)) };
            m_shape.setFillColor(sf::Color(255, 255, 255, alpha));
        }
    }
    else {
        m_shape.setFillColor(m_originalColor);
        m_shape.move({-deltaTime * m_movementSpeed, -deltaTime * m_movementSpeed});
    }
}

void Token::handleInput(sf::RenderWindow& window) {

}

sf::FloatRect Token::getBoundingBox() const {
    return m_collisionShape.getGlobalBounds();
}

void Token::draw(sf::RenderWindow& window) const {
    window.draw(m_shape);
    window.draw(m_collisionShape);
}

bool Token::isCollision(const sf::FloatRect& shape) const {

    return shape.intersects(getBoundingBox());
}

void Token::handleCollision(const sf::FloatRect& shape, Type type) {
    if (!m_isFading && isCollision(shape)) {
        m_movementSpeed = 0;
        m_isFading = true;
    }
}

void Token::setRandomPosition() {
    std::uniform_int_distribution<std::mt19937::result_type> dist(960, 1920); // distribution in range [1, 6]
    m_shape.setPosition(dist(rng), 1080);
}

bool Token::readyForRemoval() {
    if (m_shape.getPosition().y < 0) {
        m_isFading = true;
    }
    return m_readyForRemoval;
}

void Token::reset() {
    m_isLaunched = false;
    m_movementSpeed = m_defaultMovementSpeed;
    m_fadeTimer = m_fadeDuration;
    m_isFading = false;
    m_readyForRemoval = false;
    m_mark = false;
}