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
    track.LoadTrackFromFile("NewTrack.yml",window.GetSize());
    
    car.LoadTexture("car.png");
    car.SetPosition(track.GetStart());
    car.SetScale(sf::Vector2f(1,1));
    car.giveRacingLineSpline(&track.CSpline,track.getStartNode());
}
void Game::Input(sf::Event e)
{
    //car.Input(e);
    track.Input(e);
    
}
void Game::Render(Window *window)
{
    sf::RectangleShape shape;
    shape.setSize({10,10});
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(track.GetStart());

    window->BeginDraw(sf::Color::Red);
    track.Render(window);
    window->draw(shape);
    car.Render(window);
    
    window->EndDraw();
}
void Game::UI()
{

}
void Game::EarlyUpdate()
{
    track.EntityUpdate();
    if(car.isCollision(&track.temp))
    {
        
    }
    else
    {
        
    }
    car.EntityUpdate();
}
void Game::LateUpdate()
{
    
}
