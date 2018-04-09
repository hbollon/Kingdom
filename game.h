#ifndef GAME
#define GAME

#include <iostream>
#include <fstream>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include "player.h"
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
extern int gameState;

extern sf::Sprite ArrowUp;
extern sf::Sprite ArrowDown;
extern sf::Sprite ArrowRight;
extern sf::Sprite ArrowLeft;

extern sf::Texture ArrowUpT;
extern sf::Texture ArrowDownT;
extern sf::Texture ArrowRightT;
extern sf::Texture ArrowLeftT;

struct dirTable
{
    bool changeUp;
    bool changeDown;
    bool changeRight;
    bool changeLeft;
};

struct mapTable
{
    std::string mapUp;
    std::string mapDown;
    std::string mapLeft;
    std::string mapRight;
    std::string mapDiv1;
    std::string mapDiv2;
};



extern struct dirTable changeMap;
extern struct mapTable mapList;

void mainmenu();
void loadMap();
void loadCollision();
void loadTextures();
void loadMapList();
int collisionTest();

#endif // GAME

