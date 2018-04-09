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

struct mapList
{
    std::string mapUp = "";
    std::string mapDown = "";
    std::string mapLeft = "";
    std::string mapRight = "";
    std::string mapDiv1 = "";
    std::string mapDiv2 = "";
};

struct dirTable changeMap;
struct mapTable mapList;

void loadMapList()
{
    std::ifstream openfile(mapColSelected.c_str());
    int index = 1;
    std::string str;
    if(openfile.is_open())
    {
        for (int i = 0; i < 30; i++)
        {
            std::getline(openfile, str);
        }
        while(!openfile.eof())
        {
            std::string value;
            std::getline(openfile, str);
            std::stringstream stream(str);

            while(std::getline(stream, value, ' '))
            {
                if(value.length() > 3)
                {
                    switch(index)
                    {
                    case 1:
                        mapList.mapUp = value;
                        break;
                    case 2:
                        mapList.mapDown = value;
                        break;
                    case 3:
                        mapList.mapRight = value;
                        break;
                    case 4:
                        mapList.mapLeft = value;
                        break;
                    case 5:
                        mapList.mapDiv1 = value;
                        break;
                    case 6:
                        mapList.mapDiv2 = value;
                        break;

                    default:
                        break;
                    }
                    index++;
                }
            }
        }
     }
}
