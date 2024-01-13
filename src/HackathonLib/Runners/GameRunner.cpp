#include <HackathonLib/Runners/GameRunner.hpp>
#include <SFML/Graphics.hpp>

GameRunner::GameRunner(sf::RenderWindow* window) : m_window(window) {}

void GameRunner::run() {

    while (m_window->isOpen()) {
        for (auto event = sf::Event{}; m_window->pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                m_window->close();
            }
        }

        m_window->clear();
        m_character.handleInput(*m_window);
        m_character.handleCollision(m_wall.getBoundingBox(), Type::Wall);
        m_character.update();

        m_character.draw(*m_window);
        m_wall.draw(*m_window);
        m_window->display();
    }

}