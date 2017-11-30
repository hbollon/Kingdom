#include "game.h"

using namespace std;



int main()
{
    m_State = 1;
    int m_Hauteur = 1080;
    int m_Largeur = 1920;
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

    App->setVerticalSyncEnabled(true);
    App->setKeyRepeatEnabled(false);

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

           switch (m_State)
           {
             case 1:
               mainmenu();
               break;

             case 2:
               break;

             case 3:
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
                                   tiles.setPosition(j*48, i*48);
                                   tiles.setTextureRect(sf::IntRect(mapp[i][j].x *48, mapp[i][j].y *48, 48, 48));
                                   App->draw(tiles);
                               }
                       }
                   }

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
