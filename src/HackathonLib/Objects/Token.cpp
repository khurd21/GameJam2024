#include <HackathonLib/Objects/Token.hpp>
#include <HackathonLib/Type.hpp>

#include <SFML/Graphics.hpp>

#include <random>

namespace {

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist(960, 1920); // distribution in range [1, 6]

} // namespace

Token::Token(float movementSpeed) : m_movementSpeed(movementSpeed) {
    m_shape.setFillColor(sf::Color::Red);
    m_shape.setRadius(10);
}

void Token::update(float deltaTime) {
    if (m_isFading) {
        m_fadeTimer -= deltaTime;
        if (m_fadeTimer <= 0.0f) {
            m_readyForRemoval = true;
        }
        else {
            const auto alpha{ static_cast<int>(255 * (m_fadeTimer / m_fadeTimer)) };
            m_shape.setFillColor(sf::Color(255, 255, 255, alpha));
        }
    }
    else {
        m_shape.move({-deltaTime * m_movementSpeed, -deltaTime * m_movementSpeed});
    }
}

void Token::handleInput(sf::RenderWindow& window) {

}

sf::FloatRect Token::getBoundingBox() const {
    return m_shape.getGlobalBounds();
}

void Token::draw(sf::RenderWindow& window) const {
    window.draw(m_shape);
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

void Token::setRandomPosition(const sf::Vector2u& screenSize) {
    m_shape.setPosition(dist(rng), 1080);
}

bool Token::readyForRemoval() const {
    return m_readyForRemoval;
}

void Token::reset() {
    m_movementSpeed = defaultTokenSpeed;
    m_fadeTimer = defaultFadeTimer;
    m_isFading = false;
    m_readyForRemoval = false;
}