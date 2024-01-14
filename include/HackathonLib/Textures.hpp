#ifndef TEXTURES_HPP
#define TEXTURES_HPP

#include <SFML/Graphics/Texture.hpp>
#include <iostream>

const inline sf::Texture birdTexture = []() {
    sf::Texture texture;
    if (!texture.loadFromFile("resources/images/bird.png")) {
        // Handle error loading texture
        std::cout << "Could not load bird texture\n";
    }
    return texture;
}();

const inline sf::Texture coin1Texture = []() {
    sf::Texture texture;
    if (!texture.loadFromFile("resources/images/coin1.png")) {
        std::cout << "Could not load coin1 texture\n";
    }
    return texture;
}();

const inline sf::Texture coin2Texture = []() {
    sf::Texture texture;
    if (!texture.loadFromFile("resources/images/coin2.png")) {
        std::cout << "Could not load coin2 texture\n";
    }
    return texture;
}();

const inline sf::Texture cloudTexture = []() {
    sf::Texture texture;
    if (!texture.loadFromFile("resources/images/cloud.png")) {
        std::cout << "Could not load coin2 texture\n";
    }
    return texture;
}();

const inline sf::Texture time5Texture = []() {
    sf::Texture texture;
    if (!texture.loadFromFile("resources/images/time5.png")) {
        std::cout << "Could not load time5 texture\n";
    }
    return texture;
}();

const inline sf::Texture time10Texture = []() {
    sf::Texture texture;
    if (!texture.loadFromFile("resources/images/time10.png")) {
        std::cout << "Could not load time10 texture\n";
    }
    return texture;
}();


//////////////////////////////////////////////
/// sf::Images
//////////////////////////////////////////////

const inline sf::Image birdImage = []() {
    sf::Image texture;
    if (!texture.loadFromFile("resources/images/bird.png")) {
        // Handle error loading texture
        std::cout << "Could not load bird texture\n";
    }
    return texture;
}();

const inline sf::Image coin1Image = []() {
    sf::Image texture;
    if (!texture.loadFromFile("resources/images/coin1.png")) {
        std::cout << "Could not load coin1 texture\n";
    }
    return texture;
}();

const inline sf::Image coin2Image = []() {
    sf::Image texture;
    if (!texture.loadFromFile("resources/images/coin2.png")) {
        std::cout << "Could not load coin2 texture\n";
    }
    return texture;
}();

const inline sf::Image cloudImage = []() {
    sf::Image texture;
    if (!texture.loadFromFile("resources/images/cloud.png")) {
        std::cout << "Could not load coin2 texture\n";
    }
    return texture;
}();

const inline sf::Image time5Image = []() {
    sf::Image texture;
    if (!texture.loadFromFile("resources/images/time5.png")) {
        std::cout << "Could not load time5 texture\n";
    }
    return texture;
}();

const inline sf::Image time10Image = []() {
    sf::Image texture;
    if (!texture.loadFromFile("resources/images/time10.png")) {
        std::cout << "Could not load time10 texture\n";
    }
    return texture;
}();

#endif // TEXTURES_HPP