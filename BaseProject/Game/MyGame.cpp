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
}
void MyGame::LateUpdate()
{
    *log << "Game Late Update";
}
void MyGame::FixedUpdate(float dt)
{
    *log << "Game Fixed Update";
    
}
