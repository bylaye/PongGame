#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <unistd.h>


const unsigned int WIN_WIDTH = 800;
const unsigned int WIN_HEIGHT = 600;
const std::string WIN_TITLE = "Pong Game";

const float WIDTH = WIN_WIDTH * 0.95f;
const float HEIGHT = WIN_HEIGHT * 0.90f;
const int outlineThickness = 5;

const float boardPosX = (WIN_WIDTH - WIDTH) / 2;
const float boardPosY = (WIN_HEIGHT - HEIGHT) / 2;

sf::RenderWindow window(sf::VideoMode({WIN_WIDTH, WIN_HEIGHT}), WIN_TITLE);

sf::RectangleShape board({WIDTH, HEIGHT});
const int lineBoard = 5;
sf::RectangleShape boardLineTop({WIDTH, boardPosY});
float ballRadius = WIDTH / 30;
sf::CircleShape ball(ballRadius);
sf::Vector2f ballDirection = {0.4f, 0.7f};
float ballVitesse = 6.f;

const float raquetWidth = WIDTH / 30;
const float raquetHeight = HEIGHT / 5;
sf::Color outlinePlayerColor = sf::Color::White;

// player left
sf::RectangleShape leftPlayer({raquetWidth, raquetHeight});

// player right
sf::RectangleShape rightPlayer({raquetWidth, raquetHeight});

unsigned int TIME_FRESH = 50000;

#endif
