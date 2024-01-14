#include <HackathonLib/Game.hpp>
#include <HackathonLib/Type.hpp>
#include <HackathonLib/Runners/IRunner.hpp>
#include <HackathonLib/Runners/GameRunner.hpp>
#include <memory>
#include <iostream>
#include <unordered_map>

namespace
{

    enum class GameState
    {

        // This Game.cpp IS THE MENU
        Menu,
        Game,
        Instructions,
        Score,
    }; // enum class GameState

    GameState currentState{GameState::Game};

    std::unordered_map<GameState, std::unique_ptr<IRunner>> runners;

} // namespace

Game::Game() : m_window(std::make_unique<sf::RenderWindow>(sf::VideoMode(1920u, 1080u), "Hackathon"))
{
    m_window->setFramerateLimit(60);
    runners[GameState::Game] = std::make_unique<GameRunner>(m_window.get());
}

void Game::drawMenu()
{
    // Load the font in and eror handling
    sf::Font menu_font;
    if (!menu_font.loadFromFile("resources/fonts/ice-season.ttf"))
    {
        // ERROR, exit game
    }

    m_window->clear();
    // Defining menu options and sfml texts for UI
    std::vector<std::string> menu_options = {"Start Game", "Instructions", "Score", "Exit"};
    std::vector<sf::Text> menu_texts(menu_options.size());

    // Variables to help center the menu vertically
    float total_height = 0;
    float spacing = 50; // Spacing between menu items

    // First pass to calculate total height
    for (size_t i = 0; i < menu_options.size(); ++i)
    {
        menu_texts[i].setFont(menu_font);
        menu_texts[i].setString(menu_options[i]);
        menu_texts[i].setCharacterSize(60);
        sf::FloatRect text_rect = menu_texts[i].getLocalBounds();
        total_height += text_rect.height + spacing;
    }

    // Calculate starting Y position to center vertically
    float initial_y = (m_window->getSize().y - total_height) / 2.0f;

    // Second pass to set positions and draw texts
    for (size_t i = 0; i < menu_options.size(); i++)
    {
        sf::FloatRect text_rect = menu_texts[i].getLocalBounds();
        menu_texts[i].setOrigin(text_rect.left + text_rect.width / 2.0f, text_rect.top + text_rect.height / 2.0f);
        menu_texts[i].setFillColor(sf::Color::Blue);
        menu_texts[i].setPosition(m_window->getSize().x / 2.0f, initial_y + (i * (text_rect.height + spacing)));
        m_window->draw(menu_texts[i]);
    }

    m_window->display();
}

void Game::run()
{
    while (m_window->isOpen())
    {
        for (auto event = sf::Event{}; m_window->pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                m_window->close();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                std::cout << "Any Mouse Input" << std::endl;
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "Mouse Clicked" << std::endl;
                }
            }

            // if selection is Game
            // currentState = GameState::Game;
            // else if selection is Instructions
            // currentState = GameState::Instructions
            if (currentState == GameState::Menu)
            {
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        // move option up
                    }
                    else if (event.key.code == sf::Keyboard::Down)
                    {
                        // move option down
                    }
                    else if (event.key.code == sf::Keyboard::Enter)
                    {
                        // enter a change state
                    }
                }
                drawMenu();
            }
        }

        //
        if (runners.find(currentState) != runners.end())
        {
            runners[currentState]->run();
        }
        currentState = GameState::Menu;

        // update ui
        // draw
    }
}