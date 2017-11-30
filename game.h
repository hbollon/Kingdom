#ifndef GAME
#define GAME

#include <iostream>
#include <fstream>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

extern sf::Texture tileTexture;
extern sf::Sprite tiles;
extern sf::RenderWindow *App;
extern std::vector <std::vector<sf::Vector2i> > mapp;
extern std::vector <std::vector<int> > collision;
extern sf::Music music;
extern std::string mapSelected;
extern std::string mapColSelected;
extern int levelSelected;
extern int m_State;

void mainmenu();

#endif // GAME

