//
//  MyGame.cpp
//  BaseProject
//
//  Created by Daniel Harvey on 03/11/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#include "MyGame.hpp"

MyGame::MyGame(ige::FileLogger *LOG,SettingsManager *SM) : Game(LOG, SM)
{
    
}
void MyGame::Start()
{
    *log << "Game Start";
}
void MyGame::Input(std::queue<sf::Event> &events)
{
   *log << "Game Input";
}
void MyGame::Render(Window *window)
{
    *log << "Game Render";
    window->BeginDraw(sf::Color(20,55,34));
    
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
