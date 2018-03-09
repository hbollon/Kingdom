#include "player.h"

int player::TileX = 0;
int player::TileY = 10;
int player::TileXUP = 0;
int player::TileXDOWN = 0;
int player::TileXRIGHT = 0;
int player::TileXLEFT = 0;
int player::TileYUP = 8;
int player::TileYDOWN = 10;
int player::TileYRIGHT = 11;
int player::TileYLEFT = 9;

player::player()
{
    if (!tileset.loadFromFile("TilePlayer.png"))
    {
        std::cout << "Error : can't load tilePlayer.png" << std::endl;
    }
    s_player.setTexture(tileset);
    s_player.setTextureRect(sf::IntRect(TileX*75, TileY*75, 75, 75));
    s_player.setPosition(X, Y);

}

sf::Sprite player::getSprite()
{
    return s_player;
}

int player::getY()
{
    return Y;
}

int player::getX()
{
    return X;
}

void player::animation()
{
    switch (animState)
    {
    case 1:
        s_player.setTextureRect(sf::IntRect(TileXUP*75, TileYUP*75, 75, 75));
        if (TileXUP != 8)
        {
            TileXUP++;
        }
        else
        {
            TileXUP = 0;
        }
        break;

    case 2:
        s_player.setTextureRect(sf::IntRect(TileXDOWN*75, TileYDOWN*75, 75, 75));
        if (TileXDOWN != 8)
        {
            TileXDOWN++;
        }
        else
        {
            TileXDOWN = 0;
        }
        break;

    case 3:
        s_player.setTextureRect(sf::IntRect(TileXRIGHT*75, TileYRIGHT*75, 75, 75));
        if (TileXRIGHT != 8)
        {
            TileXRIGHT++;
        }
        else
        {
            TileXRIGHT = 0;
        }
        break;

    case 4:
        s_player.setTextureRect(sf::IntRect(TileXLEFT*75, TileYLEFT*75, 75, 75));
        if (TileXLEFT != 8)
        {
            TileXLEFT++;
        }
        else
        {
            TileXLEFT = 0;
        }
        break;

    default:
        break;
    }
}

void player::update()
{
    top = s_player.getPosition().y - 25;
    left = s_player.getPosition().x - 10;
    right = s_player.getPosition().x + 10;
    bottom = s_player.getPosition().y + 35;

    sf::Vector2i topLeft(sf::Vector2i((int)left / 40, (int)top / 40));
    sf::Vector2i topRight(sf::Vector2i((int)right / 40, (int)top / 40));
    sf::Vector2i bottomLeft(sf::Vector2i((int)left / 40, (int)bottom / 40));
    sf::Vector2i bottomRight(sf::Vector2i((int)right / 40, (int)bottom / 40));

    tiles.clear();

    tiles.push_back(topLeft);
    if(std::find(tiles.begin(), tiles.end(), topRight) == tiles.end()) tiles.push_back(topRight);
    if(std::find(tiles.begin(), tiles.end(), bottomLeft) == tiles.end()) tiles.push_back(bottomLeft);
    if(std::find(tiles.begin(), tiles.end(), bottomRight) == tiles.end()) tiles.push_back(bottomRight);
}

void player::position(int x, int y)
{
    s_player.setPosition(x, y);
    X = s_player.getPosition().x;
    Y = s_player.getPosition().y;
}

void player::moveUp()
{
    if (animState != 1)
    {
        animState = 1;
    }
    s_player.move(0, -3);
    X = s_player.getPosition().x;
    Y = s_player.getPosition().y;
}

void player::moveDown()
{
    if (animState != 2)
    {
        animState = 2;
    }
    s_player.move(0, 3);
    X = s_player.getPosition().x;
    Y = s_player.getPosition().y;
}

void player::moveRight()
{
    if (animState != 3)
    {
        animState = 3;
    }
    s_player.move(3, 0);
    X = s_player.getPosition().x;
    Y = s_player.getPosition().y;
}

void player::moveLeft()
{
    if (animState != 4)
    {
        animState = 4;
    }
    s_player.move(-3, 0);
    X = s_player.getPosition().x;
    Y = s_player.getPosition().y;
}

void player::colUp()
{
    s_player.move(0, 3);
    X = s_player.getPosition().x;
    Y = s_player.getPosition().y;
}

void player::colDown()
{
    s_player.move(0, -3);
    X = s_player.getPosition().x;
    Y = s_player.getPosition().y;
}

void player::colRight()
{
    s_player.move(-3, 0);
    X = s_player.getPosition().x;
    Y = s_player.getPosition().y;
}

void player::colLeft()
{
    s_player.move(3, 0);
    X = s_player.getPosition().x;
    Y = s_player.getPosition().y;
}
