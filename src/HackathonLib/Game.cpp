#include <HackathonLib/Game.hpp>
#include <HackathonLib/Type.hpp>
#include <HackathonLib/Runners/IRunner.hpp>
#include <HackathonLib/Runners/GameRunner.hpp>
#include <HackathonLib/Runners/InstructRunner.hpp>
#include <HackathonLib/Runners/ScoreRunner.hpp>
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
        Instruct,
        Score,
    }; // enum class GameState

    GameState currentState{GameState::Menu};

    std::unordered_map<GameState, std::unique_ptr<IRunner>> runners;

} // namespace

Game::Game() : m_window(std::make_unique<sf::RenderWindow>(sf::VideoMode(1920u, 1080u), "Hackathon"))
{
    m_window->setFramerateLimit(60);
    if(!m_backgroundMusic.openFromFile("resources/sounds/GameJam2024.ogg")) {
        std::cout << "No load music :(\n";
    }
    // Load background image
    if (!background_texture.loadFromFile("resources/images/background.png"))
    {
        // handle error
    }
    background_sprite.setTexture(background_texture);

    runners[GameState::Game] = std::make_unique<GameRunner>(m_window.get());
    runners[GameState::Instruct] = std::make_unique<InstructRunner>(m_window.get());
    runners[GameState::Score] = std::make_unique<ScoreRunner>(m_window.get());

    std::cout << "Background music\n";
    m_backgroundMusic.setLoop(true);
    m_backgroundMusic.setVolume(30);
}

void Game::drawMenu()
{
    m_window->clear();
    m_window->draw(background_sprite);

    // Get the current mouse position relative to the window
    sf::Vector2f mouse_position = m_window->mapPixelToCoords(sf::Mouse::getPosition(*m_window));

    // Load the font in and error handling
    sf::Font menu_font;
    if (!menu_font.loadFromFile("resources/fonts/ice-season.ttf"))
    {
        // ERROR, exit game
    }

    // Create and set up the title text
    sf::Text title_text;
    title_text.setFont(menu_font);
    title_text.setString("Ski Jump");
    title_text.setCharacterSize(80);  // Larger size for the title
    title_text.setFillColor(sf::Color::Blue);  // Color of the title
    title_text.setStyle(sf::Text::Bold);
    title_text.setStyle(sf::Text::Underlined);

    // Center the title in the window
    sf::FloatRect title_bounds = title_text.getLocalBounds();
    title_text.setOrigin(title_bounds.left + title_bounds.width / 2.0f, title_bounds.top + title_bounds.height / 2.0f);
    title_text.setPosition(m_window->getSize().x / 2.0f, 100);  // Adjust Y position as needed

    m_window->draw(title_text);

    if (!person_texture.loadFromFile("resources/images/person.png")) {
        // Handle error - For example, you could print an error message and terminate the application
        std::cout << "Error loading sprite texture" << std::endl;
    }
    
    // Set the texture to the sprite
    person_sprite.setTexture(person_texture);

    // Position the sprite at the bottom center of the window
    person_sprite.setPosition(m_window->getSize().x / 2.0f - person_sprite.getGlobalBounds().width / 2.0f, 
                       m_window->getSize().y - person_sprite.getGlobalBounds().height);

    m_window->draw(person_sprite);

    // Defining menu options and sfml texts for UI
    std::vector<std::string> menu_options = {"Start Game", "Instructions", "Score", "Exit"};
    std::vector<sf::Text> menu_texts(menu_options.size());

    float total_height = 0;
    float spacing = 50; // Spacing between menu items
    menu_options_bounds.clear();

    for (size_t i = 0; i < menu_options.size(); i++)
    {
        menu_texts[i].setFont(menu_font);
        menu_texts[i].setString(menu_options[i]);
        menu_texts[i].setCharacterSize(60);

        sf::FloatRect text_rect = menu_texts[i].getLocalBounds();
        total_height += text_rect.height + spacing;
    }

    // Calculate the initial Y position
    float initial_y = (m_window->getSize().y - total_height) / 2.0f;

    for (size_t i = 0; i < menu_options.size(); i++)
    {
        sf::FloatRect text_rect = menu_texts[i].getLocalBounds();
        menu_texts[i].setOrigin(text_rect.left + text_rect.width / 2.0f, text_rect.top + text_rect.height / 2.0f);
        menu_texts[i].setPosition(m_window->getSize().x / 2.0f, initial_y + (i * (text_rect.height + spacing)));

        // Set the default color
        menu_texts[i].setFillColor(sf::Color::Blue);

        // Store the global bounds for click detection
        sf::FloatRect global_bounds = menu_texts[i].getGlobalBounds();
        menu_options_bounds.push_back(global_bounds);

        // Change color if mouse hovers over the text
        if (global_bounds.contains(mouse_position))
        {
            menu_texts[i].setFillColor(sf::Color::Black);
        }

        m_window->draw(menu_texts[i]);
    }

    m_window->display();
}

void Game::run()
{
    m_backgroundMusic.play();
    while (m_window->isOpen())
    {
        for (auto event = sf::Event{}; m_window->pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                m_window->close();
            }

            // if selection is Game
            // currentState = GameState::Game;
            // else if selection is Instructions
            // currentState = GameState::Instructions
            if (currentState == GameState::Menu)
            {
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                {
                    // Gets the mouse's pixel location and changes it to display coordinates for mouse_position
                    sf::Vector2f mouse_position = m_window->mapPixelToCoords(
                        sf::Vector2i(event.mouseButton.x, event.mouseButton.y));

                    // Check which menu option was clicked
                    for (size_t i = 0; i < menu_options_bounds.size(); i++)
                    {
                        if (menu_options_bounds[i].contains(mouse_position))
                        {
                            // Update currentState based on which option was clicked
                            switch (i)
                            {
                            case 0:
                                currentState = GameState::Game;
                                std::cout << "Selected Game Option" << std::endl;
                                break;
                            case 1:
                                currentState = GameState::Instruct;
                                std::cout << "Selected Instructions Option" << std::endl;
                                break;
                            case 2:
                                currentState = GameState::Score;
                                std::cout << "Selected Scores Option" << std::endl;
                                break;
                            case 3:
                                m_window->close();
                                std::cout << "Selected Exit Option" << std::endl;
                                break; // Exit the game
                            }
                            break; // Break out of the for loop
                        }
                    }
                }

                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                {
                    m_window->close();
                }
            }
        }

        //
        if (runners.find(currentState) != runners.end())
        {
            runners[currentState]->run();
        }
        drawMenu();
        currentState = GameState::Menu;
        // update ui
        // draw
    }
}