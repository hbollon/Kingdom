#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "game.h"

class player
{
public:
    player();
    sf::Sprite getSprite();
    int getY();
    int getX();

    void animation();
    void update();
    void position(int x,int y);
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();

    void colUp();
    void colDown();
    void colRight();
    void colLeft();

    std::vector <sf::Vector2i> tiles;

private:
    sf::Sprite s_player;
    sf::Texture t_player;
    sf::Texture tileset;

    static int TileX;
    static int TileY;
    static int TileXUP;
    static int TileXDOWN;
    static int TileXRIGHT;
    static int TileXLEFT;
    static int TileYUP;
    static int TileYDOWN;
    static int TileYRIGHT;
    static int TileYLEFT;

    int orientation;
    int animState;
    int life;
    int damage;
    int level;
    int X = 928;
    int Y = 572;
    float top, left, right, bottom;

};

#endif // PLAYER_H
