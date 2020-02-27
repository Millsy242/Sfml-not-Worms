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
    
    ResourceHolder::get().textures.add("test");
    
    s.setTexture(ResourceHolder::get().textures.get("test"));
    s.setPosition(0, 0);
    a = myBase(4);
    b = myBase(8);
    c = myBase(56);
    d = myBase(123);
    e = myBase(987);
    
    a.Start();
    b.Start();
    c.Start();
    d.Start();
    e.Start();
    
    addObject(&a);
    addObject(&b);
    addObject(&c);
    addObject(&d);
    addObject(&e);
    
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
    Game::DebugRender(window);
    window->EndDraw();
}
void MyGame::UI()
{
    *log << "UI";
    Game::GameUI();
    a.DebugUI(0);
    b.DebugUI(1);
    c.DebugUI(2);
    d.DebugUI(3);
    e.DebugUI(4);
}
void MyGame::EarlyUpdate()
{
    *log << "Game Early Update";
   
    vy = vx = 0;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        selected++;//vy = -500;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        selected--;//vy = 500;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        vx = -500;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        vx = 500;
    
    if(selected < 0)
        selected = 0;
    if(selected >= ObjectVector.size())
        selected = (int)ObjectVector.size()-1;
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
