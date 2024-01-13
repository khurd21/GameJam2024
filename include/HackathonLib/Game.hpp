#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <HackathonLib/Runners/IRunner.hpp>

#include <memory>

class Game {
public:

    Game();
    void run();

private:
    std::unique_ptr<sf::RenderWindow> m_window = nullptr;

}; // class Game

#endif // GAME_HPP