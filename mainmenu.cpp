    #include "game.h"

void NewGame();
void LoadGame();
void Settings();

sf::Vector2f v_cursor(540, 260);

sf::Event event_menu;
sf::Texture t_menu;
sf::Sprite s_menu;
sf::Music m_titleMusic;

sf::Sprite s_cursor;
sf::Texture t_cursor;

void mainmenu()
{
    int CursorGetY;

    sf::Text w_title;
    sf::Text w_startNew;
    sf::Text w_startLoad;
    sf::Text w_option;
    sf::Text w_exit;
    sf::Font f_fantasySymb;
    sf::Font f_gameFont;

    if(!t_cursor.loadFromFile("sword.png"))
    {
        std::cout << "Error when loading Sword.png" << std::endl;
    }
    s_cursor.setTexture(t_cursor);

    if(!f_gameFont.loadFromFile("Breathe Fire.otf"))
    {
        std::cout << "Error when loading Breathe Fire.otf" << std::endl;
    }

    w_title.setString("KINGDOM");
    w_title.setFont(f_gameFont);
    w_title.setPosition(680, 60);
    w_title.setCharacterSize(140);
    w_title.setColor(sf::Color::Black);

    w_startNew.setString("NewGame");
    w_startNew.setFont(f_gameFont);
    w_startNew.setPosition(680, 280);
    w_startNew.setCharacterSize(60);
    w_startNew.setColor(sf::Color::Black);

    w_startLoad.setString("LoadGame");
    w_startLoad.setFont(f_gameFont);
    w_startLoad.setPosition(680, 360);
    w_startLoad.setCharacterSize(60);
    w_startLoad.setColor(sf::Color::Black);

    w_option.setString("Settings");
    w_option.setFont(f_gameFont);
    w_option.setPosition(680,440);
    w_option.setCharacterSize(60);
    w_option.setColor(sf::Color::Black);

    w_exit.setString("Exit");
    w_exit.setFont(f_gameFont);
    w_exit.setPosition(680, 520);
    w_exit.setCharacterSize(60);
    w_exit.setColor(sf::Color::Black);

    if(!t_menu.loadFromFile("MenuBackground.jpg"))
    {
        std::cout << "Error when loading MenuBackground.jpg" << std::endl;
    }
    s_menu.setTexture(t_menu);

    s_menu.setPosition(0, 0);
    s_cursor.setPosition(v_cursor);
    s_cursor.setScale(0.5,0.5);

    m_titleMusic.openFromFile("Heroic.ogg");
    m_titleMusic.setLoop(true);
    m_titleMusic.setVolume(100);
    m_titleMusic.play();

    while (m_State == 1)
    {
        CursorGetY = s_cursor.getPosition().y;

        while (App->pollEvent(event_menu))  //Boucle de récupération de l'event
        {
            if (event_menu.type == sf::Event::Closed)
            {
                App->close();
                m_titleMusic.stop();
            }

            if (event_menu.type == sf::Event::KeyPressed)
            {
                if (event_menu.key.code == sf::Keyboard::Escape)
                {
                    App->close();
                    m_titleMusic.stop();
                }
                else if (event_menu.key.code == sf::Keyboard::Up)
                {
                    if (s_cursor.getPosition().y == 260)
                    {
                        v_cursor.y = 500;
                        s_cursor.setPosition(v_cursor);
                    }
                    else
                    {
                        v_cursor.y -= 80;
                        s_cursor.setPosition(v_cursor);
                    }
                }
                else if (event_menu.key.code == sf::Keyboard::Down)
                {
                    if (s_cursor.getPosition().y == 500)
                    {
                        v_cursor.y = 260;
                        s_cursor.setPosition(v_cursor);
                    }
                    else
                    {
                        v_cursor.y += 80;
                        s_cursor.setPosition(v_cursor);
                    }
                }
                else if (event_menu.key.code == sf::Keyboard::Return)
                {
                    switch (CursorGetY)
                    {
                    case 260:
                        NewGame();
                        break;
                    case 340:
                        LoadGame();
                        break;
                    case 420:
                        Settings();
                        break;
                    case 500:
                        m_titleMusic.stop();
                        App->close();
                        break;
                    default:
                        break;
                    }
                }
            }
        }

        App->clear();

        App->draw(s_menu);
        App->draw(w_title);
        App->draw(w_startNew);
        App->draw(w_startLoad);
        App->draw(w_option);
        App->draw(w_exit);
        App->draw(s_cursor);

        App->display();
    }
}

void NewGame()
{
    bool b_newGameState = true;
    sf::Font f_gameFont;

    if(!f_gameFont.loadFromFile("Breathe Fire.otf"))
    {
        std::cout << "Error when loading Breathe Fire.otf" << std::endl;
    }

    sf::Text Slot1;
    sf::Text Slot2;
    sf::Text Slot3;
    sf::Text Slot4;

    if(!t_cursor.loadFromFile("sword.png"))
    {
        std::cout << "Error when loading Sword.png" << std::endl;
    }
    s_cursor.setTexture(t_cursor);

    v_cursor.x = 410.f;
    v_cursor.y = 380.f;

    s_cursor.setPosition(v_cursor);

    Slot1.setString("Slot 1");
    Slot1.setFont(f_gameFont);
    Slot1.setPosition(550, 400);
    Slot1.setCharacterSize(60);
    Slot1.setColor(sf::Color::White);

    Slot2.setString("Slot 2");
    Slot2.setFont(f_gameFont);
    Slot2.setPosition(1220, 400);
    Slot2.setCharacterSize(60);
    Slot2.setColor(sf::Color::White);

    Slot3.setString("Slot 3");
    Slot3.setFont(f_gameFont);
    Slot3.setPosition(550, 680);
    Slot3.setCharacterSize(60);
    Slot3.setColor(sf::Color::White);

    Slot4.setString("Slot 4");
    Slot4.setFont(f_gameFont);
    Slot4.setPosition(1220, 680);
    Slot4.setCharacterSize(60);
    Slot4.setColor(sf::Color::White);

    while (b_newGameState == true)
    {
        while (App->pollEvent(event_menu))  //Boucle de récupération de l'event
        {
            if (event_menu.type == sf::Event::Closed)
            {
                App->close();
                m_titleMusic.stop();
            }

            if (event_menu.type == sf::Event::KeyPressed)
            {
                if (event_menu.key.code == sf::Keyboard::Escape)
                {
                    v_cursor.x = 540;
                    v_cursor.y = 260;
                    s_cursor.setPosition(v_cursor);
                    b_newGameState = false;
                }
                else if (event_menu.key.code == sf::Keyboard::Up)
                {
                    if (s_cursor.getPosition().y == 380)
                    {
                        v_cursor.y = 660;
                        s_cursor.setPosition(v_cursor);
                    }
                    else
                    {
                        v_cursor.y -= 280;
                        s_cursor.setPosition(v_cursor);
                    }
                }
                else if (event_menu.key.code == sf::Keyboard::Down)
                {
                    if (s_cursor.getPosition().y == 660)
                    {
                        v_cursor.y = 380;
                        s_cursor.setPosition(v_cursor);
                    }
                    else
                    {
                        v_cursor.y += 280;
                        s_cursor.setPosition(v_cursor);
                    }
                }
                else if (event_menu.key.code == sf::Keyboard::Right)
                {
                    if (s_cursor.getPosition().x == 1080)
                    {
                        v_cursor.x = 410;
                        s_cursor.setPosition(v_cursor);
                    }
                    else
                    {
                        v_cursor.x += 670;
                        s_cursor.setPosition(v_cursor);
                    }
                }
                else if (event_menu.key.code == sf::Keyboard::Left)
                {
                    if (s_cursor.getPosition().x == 410)
                    {
                        v_cursor.x = 1080;
                        s_cursor.setPosition(v_cursor);
                    }
                    else
                    {
                        v_cursor.x -= 670;
                        s_cursor.setPosition(v_cursor);
                    }
                }
                else if (event_menu.key.code == sf::Keyboard::Return)
                {
                    if (s_cursor.getPosition().x == 410)
                    {
                        v_cursor.x = 1080;
                        s_cursor.setPosition(v_cursor);
                    }
                    else if ()
                    {
                        v_cursor.x -= 670;
                        s_cursor.setPosition(v_cursor);
                    }
                    else if ()
                    {

                    }
                    else if ()
                    {

                    }
                }
            }
        }
        App->clear();
        App->draw(s_menu);
        App->draw(s_cursor);
        App->draw(Slot1);
        App->draw(Slot2);
        App->draw(Slot3);
        App->draw(Slot4);
        App->display();
    }
}

void LoadGame()
{

}

void Settings()
{

}
