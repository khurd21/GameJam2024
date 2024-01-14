#include <HackathonLib/Runners/InstructRunner.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

InstructRunner::InstructRunner(sf::RenderWindow *window) : m_window(window)
{
    if (!background_texture.loadFromFile("../../resources/images/background.png"))
    {
        // handle error
    }
    background_sprite.setTexture(background_texture);

    // Load font
    if (!i_font.loadFromFile("../../resources/fonts/ice-season.ttf")) {
        // Handle error
    }

    // Set up the text
    i_text.setFont(i_font);
    i_text.setString("How to Play");
    i_text.setCharacterSize(80);          
    i_text.setFillColor(sf::Color::Blue); // Color of the title
    i_text.setStyle(sf::Text::Bold);
    i_text.setStyle(sf::Text::Underlined);

    // Center the title in the window
    sf::FloatRect title_bounds = i_text.getLocalBounds();
    i_text.setOrigin(title_bounds.left + title_bounds.width / 2.0f, title_bounds.top + title_bounds.height / 2.0f);
    i_text.setPosition(m_window->getSize().x / 2.0f, 100);

    // Put HELP TEXT HERE


    // Person Sprite
    if (!person_texture.loadFromFile("../../resources/images/person.png")) {
        std::cout << "Error loading sprite texture" << std::endl;
    }
    
    // Set the texture to the sprite
    person_sprite.setTexture(person_texture);

    // position and origin for person sprite
    sf::FloatRect person_bounds = person_sprite.getLocalBounds();
    person_sprite.setOrigin(person_bounds.left + person_bounds.width / 2.0f, person_bounds.top + person_bounds.height / 2.0f);
    person_sprite.setPosition(m_window->getSize().x / 2.0f, m_window->getSize().y / 2.0f);


    // Bird Sprite
    if (!bird_texture.loadFromFile("../../resources/images/bird.png")) {
        std::cout << "Error loading sprite texture" << std::endl;
    }
    
    // Set the texture to the sprite
    bird_sprite.setTexture(bird_texture);

    //  position and origin for bird sprite
    sf::FloatRect bird_bounds = bird_sprite.getLocalBounds();
    bird_sprite.setOrigin(bird_bounds.left + bird_bounds.width / 2.0f, bird_bounds.top + bird_bounds.height / 2.0f);
    bird_sprite.setPosition(m_window->getSize().x / 2.0f, m_window->getSize().y / 2.0f);



    // Cloud Sprite
    if (!cloud_texture.loadFromFile("../../resources/images/cloud.png")) {
        std::cout << "Error loading sprite texture" << std::endl;
    }
    
    // Set the texture to the sprite
    cloud_sprite.setTexture(cloud_texture);

    //  position and origin for cloud sprite
    sf::FloatRect cloud_bounds = cloud_sprite.getLocalBounds();
    cloud_sprite.setOrigin(cloud_bounds.left + cloud_bounds.width / 2.0f, cloud_bounds.top + cloud_bounds.height / 2.0f);
    cloud_sprite.setPosition(m_window->getSize().x / 2.0f, m_window->getSize().y / 2.0f);



    // Coin1 Sprite
    if (!coin1_texture.loadFromFile("../../resources/images/coin1.png")) {
        std::cout << "Error loading sprite texture" << std::endl;
    }
    
    // Set the texture to the sprite
    coin1_sprite.setTexture(coin1_texture);

    //  position and origin for coin1 sprite
    sf::FloatRect coin1_bounds = coin1_sprite.getLocalBounds();
    coin1_sprite.setOrigin(coin1_bounds.left + coin1_bounds.width / 2.0f, coin1_bounds.top + coin1_bounds.height / 2.0f);
    coin1_sprite.setPosition(m_window->getSize().x / 2.0f, m_window->getSize().y / 2.0f);



    // Coin2 Sprite
    if (!coin2_texture.loadFromFile("../../resources/images/coin2.png")) {
        std::cout << "Error loading sprite texture" << std::endl;
    }
    
    // Set the texture to the sprite
    coin2_sprite.setTexture(coin2_texture);

    //  position and origin for coin2 sprite
    sf::FloatRect coin2_bounds = coin2_sprite.getLocalBounds();
    coin2_sprite.setOrigin(coin2_bounds.left + coin2_bounds.width / 2.0f, coin2_bounds.top + coin2_bounds.height / 2.0f);
    coin2_sprite.setPosition(m_window->getSize().x / 2.0f, m_window->getSize().y / 2.0f);



    // Time5 Sprite
    if (!time5_texture.loadFromFile("../../resources/images/time5.png")) {
        std::cout << "Error loading sprite texture" << std::endl;
    }
    
    // Set the texture to the sprite
    time5_sprite.setTexture(time5_texture);

    //  position and origin for time5 sprite
    sf::FloatRect time5_bounds = time5_sprite.getLocalBounds();
    time5_sprite.setOrigin(time5_bounds.left + time5_bounds.width / 2.0f, time5_bounds.top + time5_bounds.height / 2.0f);
    time5_sprite.setPosition(m_window->getSize().x / 2.0f, m_window->getSize().y / 2.0f);



    // Time10 Sprite
    if (!time10_texture.loadFromFile("../../resources/images/time10.png")) {
        std::cout << "Error loading sprite texture" << std::endl;
    }
    
    // Set the texture to the sprite
    time10_sprite.setTexture(time10_texture);

    //  position and origin for time10 sprite
    sf::FloatRect time10_bounds = time10_sprite.getLocalBounds();
    time10_sprite.setOrigin(time10_bounds.left + time10_bounds.width / 2.0f, time10_bounds.top + time10_bounds.height / 2.0f);
    time10_sprite.setPosition(m_window->getSize().x / 2.0f, m_window->getSize().y / 2.0f);

}

void InstructRunner::drawInstruct() {
    m_window->draw(background_sprite);
    m_window->draw(i_text);
    m_window->draw(person_sprite);

}

void InstructRunner::run()
{
    std::cout << "IN INSTRUCTIONS" << std::endl;
    while (m_window->isOpen())
    {
        // Process events
        for (auto event = sf::Event{}; m_window->pollEvent(event);)
        {
            if (event.type == sf::Event::Closed) {
                m_window->close();
            } 
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                return;
            }
        }

        // Clear the window
        m_window->clear();

        // Draws everything
        drawInstruct();
        
        // Update the window
        m_window->display();
    }
}
