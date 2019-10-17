//
//  Game.cpp
//  BaseProject
//
//  Created by Daniel Harvey on 13/09/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#include "Game.hpp"
#include <iostream>
Game::Game()
{
    
}

void Game::Start()
{
       Active = true;
    r.setSize(sf::Vector2f(60,60));
    r.setPosition(window->GetCentre().x,window->GetCentre().y);
    r.setFillColor(sf::Color::Black);
}
void Game::Input(sf::Event e)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        r.move(2, 2);
    }
}
void Game::Render(Window *window)
{
    window->BeginDraw(sf::Color::Red);

    window->draw(r);
    
    window->EndDraw();
}
void Game::UI()
{
    ImGui::Begin("Game");
    if(ImGui::Button("change to menu"))
    {
         std::cout<<"stop Game\n";
         Active = false;
    }
    ImGui::End();
}
void Game::EarlyUpdate()
{

}
void Game::LateUpdate()
{
    
}
