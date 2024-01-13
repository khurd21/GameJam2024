#include <HackathonLib/Game.hpp>
#include <HackathonLib/Type.hpp>
#include <memory>
#include <iostream>

Game::Game() : m_window(std::make_unique<sf::RenderWindow>(sf::VideoMode(1920u, 1080u), "Hackathon")) {}

void Game::run() {
    m_window->setFramerateLimit(60);
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