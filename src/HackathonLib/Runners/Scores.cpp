#include <HackathonLib/Runners/ScoreRunner.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

ScoreRunner::ScoreRunner(sf::RenderWindow *window) : m_window(window), current_username("wsu")
{
    if (!background_texture.loadFromFile("../../resources/images/background.png"))
    {
        // handle error
    }
    background_sprite.setTexture(background_texture);

    if (!sign_texture.loadFromFile("../../resources/images/sign.png"))
    {
        // handle error
    }
    sign_sprite.setTexture(sign_texture);
    // position and origin for person sprite
    sf::FloatRect sign_bounds = sign_sprite.getLocalBounds();
    sign_sprite.setOrigin(sign_bounds.left + sign_bounds.width / 2.0f, sign_bounds.top + sign_bounds.height / 2.0f);
    sign_sprite.setPosition(m_window->getSize().x / 2.0f, 650);

    sign_sprite.setScale(2.5, 1.5);

    loadScoresFromFile("../../resources/ski_jump_data.csv");
    m_window->clear();

    std::cout << "Scores:\n";
    for (const auto &scoreEntry : scores)
    {
        std::string username = std::get<0>(scoreEntry); // Get the username
        int score = std::get<1>(scoreEntry);            // Get the score
        std::cout << "Username: " << username << ", Score: " << score << "\n";
    }

    // Load font
    if (!i_font.loadFromFile("../../resources/fonts/ice-season.ttf"))
    {
        // Handle error
    }

    // Set up the text
    i_text.setFont(i_font);
    i_text.setString("Username and Top Scores");
    i_text.setCharacterSize(80);
    i_text.setFillColor(sf::Color::Blue); // Color of the title
    i_text.setStyle(sf::Text::Bold);
    i_text.setStyle(sf::Text::Underlined);

    // Center the title in the window
    sf::FloatRect title_bounds = i_text.getLocalBounds();
    i_text.setOrigin(title_bounds.left + title_bounds.width / 2.0f, title_bounds.top + title_bounds.height / 2.0f);
    i_text.setPosition(m_window->getSize().x / 2.0f, 100);

    help_text_1.setFont(i_font);
    help_text_1.setString("Press 'Enter' or 'Escape' to save username go back to menu");
    help_text_1.setCharacterSize(30);
    help_text_1.setFillColor(sf::Color::White); // Color of the title
    help_text_1.setStyle(sf::Text::Bold);

    help_text_2.setFont(i_font);
    help_text_2.setString("Start typing to create and/or change your username");
    help_text_2.setCharacterSize(30);
    help_text_2.setFillColor(sf::Color::White); // Color of the title
    help_text_2.setStyle(sf::Text::Bold);

    sf::FloatRect help1_bounds = help_text_1.getLocalBounds();
    help_text_1.setOrigin(help1_bounds.left + help1_bounds.width / 2.0f, help1_bounds.top + help1_bounds.height / 2.0f);
    help_text_1.setPosition(680, 400);

    sf::FloatRect help2_bounds = help_text_2.getLocalBounds();
    help_text_2.setOrigin(help2_bounds.left + help2_bounds.width / 2.0f, help2_bounds.top + help2_bounds.height / 2.0f);
    help_text_2.setPosition(680, 450);
}

void ScoreRunner::loadScoresFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string username;
        int score;
        if (std::getline(ss, username, ',') && ss >> score)
        {
            scores.push_back(std::make_tuple(username, score));
        }
    }
}

void ScoreRunner::drawUsername()
{
    sf::Text username_title;
    username_title.setFont(i_font);
    username_title.setString("Change Username");
    username_title.setCharacterSize(50);
    username_title.setFillColor(sf::Color::White);
    username_title.setStyle(sf::Text::Bold);
    username_title.setStyle(sf::Text::Underlined);

    sf::FloatRect titleBounds = username_title.getLocalBounds();
    username_title.setOrigin(titleBounds.width / 2.0f, 0);         // Origin at the top center of the title
    username_title.setPosition(480, m_window->getSize().y / 2.0f); // Adjust position as needed

    m_window->draw(username_title);

    current_username_text.setFont(i_font);
    current_username_text.setCharacterSize(40);
    current_username_text.setFillColor(sf::Color::White);
    current_username_text.setString("Username: " + current_username);

    sf::FloatRect current_username_bounds = current_username_text.getLocalBounds();
    current_username_text.setOrigin(current_username_bounds.left + current_username_bounds.width / 2.0f, current_username_bounds.top + current_username_bounds.height / 2.0f);
    current_username_text.setPosition(480, (m_window->getSize().y / 2.0f) + 100);

    // Move the username input text below the "Username" title

    // Add user input function here
    m_window->draw(current_username_text);
}

void ScoreRunner::drawScores()
{
    // Title setup
    sf::Text title_text;
    title_text.setFont(i_font);
    title_text.setString("Top Scores");
    title_text.setCharacterSize(50);
    title_text.setFillColor(sf::Color::White);
    title_text.setStyle(sf::Text::Bold);
    title_text.setStyle(sf::Text::Underlined);

    // Set the title position
    sf::FloatRect titleBounds = title_text.getLocalBounds();
    title_text.setOrigin(titleBounds.width / 2.0f, 0);          // Origin at the top center of the title
    title_text.setPosition(1440, m_window->getSize().y / 4.0f); // Set X position to 1440 px

    m_window->draw(title_text);

    // Score setup
    sf::Text score_text;
    score_text.setFont(i_font);
    score_text.setCharacterSize(40);
    score_text.setFillColor(sf::Color::White);
    score_text.setStyle(sf::Text::Bold);

    // Starting position for scores just below the title
    float startY = title_text.getPosition().y + titleBounds.height + 20.0f; // 10 pixels below the title
    float spacing = 50.0f;                                                  // Vertical spacing between scores

    // Iterate and draw each score
    for (size_t i = 0; i < scores.size(); i++)
    {
        std::string username = std::get<0>(scores[i]);
        int score = std::get<1>(scores[i]);
        score_text.setString(username + ": " + std::to_string(score));

        // Align text horizontally at 1440 px
        sf::FloatRect textRect = score_text.getLocalBounds();
        score_text.setOrigin(textRect.width / 2.0f, 0);     // Origin at the top center of the score text
        score_text.setPosition(1440, startY + i * spacing); // Align horizontally at 1440 px

        m_window->draw(score_text);
    }
}

void ScoreRunner::run()
{
    std::cout << "IN Scores" << std::endl;
    while (m_window->isOpen())
    {
        // Process events
        for (auto event = sf::Event{}; m_window->pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                m_window->close();
            }
            else if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode < 128)
                {
                    // Basic ASCII input, including letters and numbers
                    char input_character = static_cast<char>(event.text.unicode);

                    if (std::isalnum(input_character))
                    {
                        // only allows letters
                        current_username += input_character;
                        current_username_text.setString("Username: " + current_username);
                    }
                }
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                // checking if the user had change the usewrname to be nothing
                if (event.key.code == sf::Keyboard::BackSpace)
                {
                    if (!current_username.empty())
                    {
                        current_username.pop_back(); // Removes the last character
                    }
                    else
                    {
                        current_username = "wsu"; // Reset to default "wsu" when username is empty
                        current_username_text.setString("Username: " + current_username);
                    }
                }
                if (event.key.code == sf::Keyboard::Escape || event.key.code == sf::Keyboard::Enter)
                {
                    return; // Exit on ESC or Enter
                }
            }

            // Clear the window
            m_window->clear();

            m_window->draw(background_sprite);
            m_window->draw(sign_sprite);

            m_window->draw(help_text_1);
            m_window->draw(help_text_2);

            drawUsername();

            // Draw the text
            m_window->draw(i_text);
            drawScores();

            // Update the window
            m_window->display();
        }
    }
}
