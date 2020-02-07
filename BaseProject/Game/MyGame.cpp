//
//  MyGame.cpp
//  BaseProject
//
//  Created by Daniel Harvey on 03/11/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#include "MyGame.hpp"

MyGame::MyGame(std::shared_ptr<ige::FileLogger> LOG,std::shared_ptr<SettingsManager> SM) : Game(LOG, SM)
{
    
}
void MyGame::Start()
{
    *log << "Game Start";
    t.loadFromFile("test.png");
    s.setTexture(t);
    s.setPosition(0, 0);
    
    SetGameArea(myRect(40,40,window->GetSize().x-40,window->GetSize().y-40));
}
void MyGame::Input(std::queue<sf::Event> &events, float dt)
{
   *log << "Game Input";

}
void MyGame::Render(std::shared_ptr<Window> window)
{
    *log << "Game Render";
    window->BeginDraw(sf::Color(20,55,34));
    window->draw(s);
    window->draw(GameArea);
    window->EndDraw();
}
void MyGame::UI()
{
    *log << "UI";
    Game::GameUI();
}
void MyGame::EarlyUpdate()
{
    *log << "Game Early Update";
   
    vy = vx = 0;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        vy = -500;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        vy = 500;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        vx = -500;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        vx = 500;
}
void MyGame::LateUpdate()
{
    *log << "Game Late Update";
}
void MyGame::FixedUpdate(float dt)
{
    *log << "Game Fixed Update";
     s.move(vx*dt, vy*dt);
}
