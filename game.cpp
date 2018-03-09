#include "game.h"

sf::Texture tileTexture;
sf::Sprite tiles;
sf::RenderWindow *App;
std::vector <std::vector<sf::Vector2i> > mapp;
std::vector <std::vector<int> > collision;
sf::Music music;
std::string mapSelected = "map.txt";
std::string mapColSelected = "colMap.txt";
int levelSelected;
int gameState;
int arrow = 0;

sf::Sprite ArrowUp;
sf::Sprite ArrowDown;
sf::Sprite ArrowRight;
sf::Sprite ArrowLeft;

sf::Texture ArrowUpT;
sf::Texture ArrowDownT;
sf::Texture ArrowRightT;
sf::Texture ArrowLeftT;

struct changeMap
{
    bool changeUp = false;
    bool changeDown = false;
    bool changeRight = false;
    bool changeLeft = false;
};

struct dirTable changeMap;
