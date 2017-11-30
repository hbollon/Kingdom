#include "game.h"

sf::Texture tileTexture;
sf::Sprite tiles;
sf::RenderWindow *App;
std::vector <std::vector<sf::Vector2i> > mapp;
std::vector <std::vector<int> > collision;
sf::Music music;
std::string mapSelected;
std::string mapColSelected;
int levelSelected;
int m_State;
