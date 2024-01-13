#include <HackathonLib/Wall.hpp>
#include <HackathonLib/Type.hpp>
#include <SFML/Graphics.hpp>

Wall::Wall(float x, float y, float width, float height) {
    m_shape.setPosition(x, y);
    m_shape.setSize({width, height});
    m_shape.setFillColor(sf::Color::Green);
    m_shape.setOrigin(width / 2.0f, height / 2.0f);
}

void Wall::update() {}

void Wall::handleInput(sf::RenderWindow& window) {}

sf::FloatRect Wall::getBoundingBox() const {
    return m_shape.getGlobalBounds();
}

void Wall::draw(sf::RenderWindow& window) const {
    window.draw(m_shape);
}


bool Wall::isCollision(const sf::FloatRect& shape) const {
    return false;
}

void Wall::handleCollision(const sf::FloatRect& shape, enum Type) {

}