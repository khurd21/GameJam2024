#include <HackathonLib/Game.hpp>
#include <HackathonLib/Type.hpp>
#include <HackathonLib/Runners/IRunner.hpp>
#include <HackathonLib/Runners/GameRunner.hpp>
#include <memory>
#include <iostream>
#include <unordered_map>

namespace {

enum class GameState {

    // This Game.cpp IS THE MENU
    Game,

}; // enum class GameState

GameState currentState{ GameState::Game };

std::unordered_map<GameState, std::unique_ptr<IRunner>> runners;

} // namespace

Game::Game() : m_window(std::make_unique<sf::RenderWindow>(sf::VideoMode(1920u, 1080u), "Hackathon")) {
    m_window->setFramerateLimit(60);
    runners[GameState::Game] = std::make_unique<GameRunner>(m_window.get());
}

void Game::run() {
    while (m_window->isOpen()) {
        for (auto event = sf::Event{}; m_window->pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                m_window->close();
            }
            // if selection is Game
            // currentState = GameState::Game;
            // else if selection is Instructions
            // currentState = GameState::Instructions
        }

        // 
        if (runners.find(currentState) != runners.end()) {
            runners[currentState]->run();
        }

        // update ui
        // draw
    }

}