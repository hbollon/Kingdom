#include "game.h"

using namespace std;

player Player;

int main()
{
    gameState = 1;
    int m_Hauteur = 1080;
    int m_Largeur = 1920;
    int direction;
    bool m_fullscreen = false;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    if (m_fullscreen == true) //Mode plein écran
    {
        App = new sf::RenderWindow (sf::VideoMode(m_Largeur, m_Hauteur, 32), "Tales of a Survivor", sf::Style::Fullscreen);
    }

    else if (m_fullscreen == false) //Mode fenetré
    {
        App = new sf::RenderWindow (sf::VideoMode(m_Largeur, m_Hauteur, 32), "Tales of a Survivor");
    }

    App->setVerticalSyncEnabled(false);
    App->setFramerateLimit(60);
    App->setKeyRepeatEnabled(false);

    loadMap();
    loadCollision();
    loadTextures();

    //player Player;

    while (App->isOpen()) //Boucle de jeu
       {
           sf::Event Event;        //Crétion d'un évènement

           while (App->pollEvent(Event))  //Boucle de récupération de l'event
           {
               if (Event.type == sf::Event::Closed)
               {
                   App->close();
               }

               if (Event.type == sf::Event::KeyPressed)
               {
                   if (Event.key.code == sf::Keyboard::Escape)
                   {
                       App->close();
                   }
               }
           }

           if (sf::Keyboard::isKeyPressed((sf::Keyboard::Z)) || sf::Keyboard::isKeyPressed((sf::Keyboard::Up)))
           {
               direction = 1;
               Player.moveUp();
               Player.animation();
           }
           if (sf::Keyboard::isKeyPressed((sf::Keyboard::S)) || sf::Keyboard::isKeyPressed((sf::Keyboard::Down)))
           {
               direction = 2;
               Player.moveDown();
               Player.animation();
           }
           if  (((sf::Keyboard::isKeyPressed((sf::Keyboard::D)) && ((sf::Keyboard::isKeyPressed((sf::Keyboard::Z))) == false) && ((sf::Keyboard::isKeyPressed((sf::Keyboard::S)))) == false) || (sf::Keyboard::isKeyPressed((sf::Keyboard::Right))) && ((sf::Keyboard::isKeyPressed((sf::Keyboard::Up))) == false) && ((sf::Keyboard::isKeyPressed((sf::Keyboard::Down)))) == false))
           {
               direction = 3;
               Player.moveRight();
               Player.animation();
           }
           if (((sf::Keyboard::isKeyPressed((sf::Keyboard::Q)) && ((sf::Keyboard::isKeyPressed((sf::Keyboard::Z))) == false) && ((sf::Keyboard::isKeyPressed((sf::Keyboard::S)))) == false) || (sf::Keyboard::isKeyPressed((sf::Keyboard::Left))) && ((sf::Keyboard::isKeyPressed((sf::Keyboard::Up))) == false) && ((sf::Keyboard::isKeyPressed((sf::Keyboard::Down)))) == false))
           {
               direction = 4;
               Player.moveLeft();
               Player.animation();
           }
           if (sf::Keyboard::isKeyPressed((sf::Keyboard::E)))
           {

               if (changeMap.changeUp == true)
               {
                    Player.position(80, Player.getY());
                    mapSelected = "mapUp.txt";
                    mapColSelected = "colMapEmpty.txt";
                    loadMap();
                    loadCollision();
               }
               else if (changeMap.changeDown == true)
               {
                    Player.position(80, Player.getY());
                    mapSelected = "mapDown.txt";
                    mapColSelected = "colMapEmpty.txt";
                    loadMap();
                    loadCollision();
               }
               else if (changeMap.changeRight == true)
               {
                    Player.position(80, Player.getY());
                    mapSelected = "mapRight.txt";
                    mapColSelected = "colMapEmpty.txt";
                    loadMap();
                    loadCollision();
               }
               else if (changeMap.changeLeft == true)
               {
                    Player.position(80, Player.getY());
                    mapSelected = "mapLeft.txt";
                    mapColSelected = "colMapEmpty.txt";
                    loadMap();
                    loadCollision();
               }
           }


           Player.update();

           int colTest = collisionTest();
           switch(colTest)
           {
           case (1):
               switch (direction)
               {
               case (1):
                       Player.colUp();
                   break;

              case (2):
                       Player.colDown();
                   break;

               case (3):
                       Player.colRight();
                   break;

               case (4):
                       Player.colLeft();
                   break;

               default:
                   break;
               }
               break;

           case (2):
                arrow = 1;
               break;

           case (3):
               arrow = 2;
               break;

           case (4):
               arrow = 3;
               break;

           case (5):
               arrow = 4;
               break;

           default:
               arrow = 0;
               break;
           }

           switch (gameState)
           {
             case 1:
               mainmenu();
               break;

             default:
               break;
           }

           App->clear();

           for(int i=0; i<mapp.size(); i++)
                   {
                   for(int j=0; j<mapp[i].size(); j++)
                       {
                           if(mapp[i][j].x !=-1 && mapp[i][j].y !=-1)
                               {
                                   tiles.setPosition(j*40, i*40);
                                   tiles.setTextureRect(sf::IntRect(mapp[i][j].x *40, mapp[i][j].y *40, 40, 40));
                                   App->draw(tiles);
                               }
                       }
                   }

           if (arrow == 1)
           {
               ArrowUp.setPosition(Player.getSprite().getPosition().x + 15, Player.getSprite().getPosition().y + 70);
               changeMap.changeUp = true;
               App->draw(ArrowUp);
           }
           else
           {
                changeMap.changeUp = false;
           }
           if (arrow == 2)
           {
               ArrowDown.setPosition(Player.getSprite().getPosition().x + 13, Player.getSprite().getPosition().y - 60);
               changeMap.changeDown = true;
               App->draw(ArrowDown);
           }
           else
           {
                changeMap.changeDown = false;
           }
           if (arrow == 3)
           {
               ArrowRight.setPosition(Player.getSprite().getPosition().x - 60, Player.getSprite().getPosition().y + 20);
               changeMap.changeRight = true;
               App->draw(ArrowRight);
           }
           else
           {
                changeMap.changeRight = false;
           }
           if (arrow == 4)
           {
               ArrowLeft.setPosition(Player.getSprite().getPosition().x + 60, Player.getSprite().getPosition().y + 20);
               changeMap.changeLeft = true;
               App->draw(ArrowLeft);
           }
           else
           {
                changeMap.changeLeft = false;
           }

           App->draw(Player.getSprite());
           App->display();
       }
}

void loadMap() //Chargement de la map
{
    std::ifstream openfile(mapSelected.c_str());
    std::vector<sf::Vector2i> tempMap;
    mapp.clear();

    if(openfile.is_open())
    {
        std::string tileLocation;
        openfile >> tileLocation;
        tileTexture.loadFromFile(tileLocation);
        tiles.setTexture(tileTexture);

        while(!openfile.eof())
        {
            std::string str, value;
            std::getline(openfile, str);
            std::stringstream stream(str);

            while(std::getline(stream, value, ' '))
            {
                if(value.length() > 0)
                {
                    std::string xx = value.substr(0, value.find(','));
                    std::string yy = value.substr(value.find(',') + 1);

                    int x, y, i, j;

                    for(i = 0; i < xx.length(); i++)
                    {
                        if(!isdigit(xx[i]))
                            break;
                    }

                    for(j = 0; j < yy.length(); j++)
                    {
                        if(!isdigit(yy[j]))
                            break;
                    }

                    x = (i == xx.length()) ? atoi(xx.c_str()) : -1;
                    y = (j == yy.length()) ? atoi(yy.c_str()) : -1;

                    tempMap.push_back(sf::Vector2i(x, y));
                 }
            }
            if(tempMap.size() > 0)
            {
                mapp.push_back(tempMap);
                tempMap.clear();
            }
        }
     }
}

void loadCollision() //Chargement de la map de collision
{
    std::ifstream openfile(mapColSelected.c_str());
    std::vector<int> tempMap;
    collision.clear();

    if(openfile.is_open())
    {
        while(!openfile.eof())
        {
            std::string str, value;
            std::getline(openfile, str);
            std::stringstream stream(str);

            while(std::getline(stream, value, ' '))
            {
                if(value.length() > 0)
                {
                    int a = atoi(value.c_str());
                    tempMap.push_back(a);
                }
            }
                collision.push_back(tempMap);
                tempMap.clear();
        }
     }
}

int loadMusic() //Selection de la musique en fonction du niveau
{
    switch (levelSelected)
    {

    case 1:
        if (!music.openFromFile("Aeon_Metropolis.wav"))
            return -1;

        break;

    default:
        break;

    }

    return 0;
}

int collisionTest()
{
    int out = 0;
    for(int i = 0; i < Player.tiles.size(); i++)
    {
        if(collision[Player.tiles[i].y][Player.tiles[i].x] == 1)
        {
            out = 1;
        }
        else if(collision[Player.tiles[i].y][Player.tiles[i].x] == 2)
        {
            out = 2;
        }
        else if(collision[Player.tiles[i].y][Player.tiles[i].x] == 3)
        {
            out = 3;
        }
        else if(collision[Player.tiles[i].y][Player.tiles[i].x] == 4)
        {
            out = 4;
        }
        else if(collision[Player.tiles[i].y][Player.tiles[i].x] == 5)
        {
            out = 5;
        }
    }

    return out;
}

void loadTextures()
{
    if (!ArrowUpT.loadFromFile("arrowU.png"))
    {
        std::cout << "Error : can't load arrowU.png" << std::endl;
    }
    ArrowUp.setTexture(ArrowUpT);

    if (!ArrowDownT.loadFromFile("arrowD.png"))
    {
        std::cout << "Error : can't load arrowD.png" << std::endl;
    }
    ArrowDown.setTexture(ArrowDownT);

    if (!ArrowRightT.loadFromFile("arrowR.png"))
    {
        std::cout << "Error : can't load arrowR.png" << std::endl;
    }
    ArrowRight.setTexture(ArrowRightT);

    if (!ArrowLeftT.loadFromFile("arrowL.png"))
    {
        std::cout << "Error : can't load arrowL.png" << std::endl;
    }
    ArrowLeft.setTexture(ArrowLeftT);
}
