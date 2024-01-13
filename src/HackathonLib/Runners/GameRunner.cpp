#include <HackathonLib/Runners/GameRunner.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

GameRunner::GameRunner(sf::RenderWindow* window) : m_window(window), m_birds(1) {
    for (auto& bird : m_birds) {
        bird.setRandomPosition(m_window->getSize());

        std::cout << "Bird at: " << bird.getBoundingBox().left << ", " << bird.getBoundingBox().top << '\n';
    }
}

void GameRunner::run() {
    sf::Clock clock;
    float deltaTime{ clock.restart().asSeconds() };

    while (m_window->isOpen()) {
        for (auto event = sf::Event{}; m_window->pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                m_window->close();
            }
        }

        deltaTime = clock.restart().asSeconds();

        m_window->clear();
        m_character.handleInput(*m_window);
        m_character.update(deltaTime);
        for (auto& bird : m_birds) {
            bird.update(deltaTime);
            bird.handleCollision(m_character.getBoundingBox(), Type::Character);
            if (bird.readyForRemoval()) {
                bird.reset();
                bird.setRandomPosition(m_window->getSize());
            }
        }

        for (auto& bird : m_birds) {
            bird.draw(*m_window);
        }

        m_character.draw(*m_window);
        m_window->display();
    }

}