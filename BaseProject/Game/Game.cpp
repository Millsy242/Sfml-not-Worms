//
//  Game.cpp
//  BaseProject
//
//  Created by Daniel Harvey on 13/09/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#include "Game.hpp"

Game::Game()
{
    window.SetTitle("Game");
}

void Game::Start()
{

}
void Game::Input(sf::Event e)
{

    
}
void Game::Render(Window *window)
{
    window->BeginDraw(sf::Color::Red);

    
    window->EndDraw();
}
void Game::UI()
{

}
void Game::EarlyUpdate()
{

}
void Game::LateUpdate()
{
    
}
