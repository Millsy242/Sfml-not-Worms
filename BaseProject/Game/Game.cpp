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
         Active = false;
    }
    if(ImGui::Button("pause"))
    {
         Pause = !Pause;
    }
    if(ImGui::Button("ImGui Debug"))
    {
        ImGui::ShowMetricsWindow();
    }
    ImGui::End();
    
    if(Pause)
    {
        ImGuiWindowFlags window_flags = 0;
        window_flags |= ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_NoNav;
        window_flags |= ImGuiWindowFlags_NoCollapse;
        window_flags |= ImGuiWindowFlags_NoNavFocus;
        window_flags |= ImGuiWindowFlags_NoTitleBar;
        window_flags |= ImGuiWindowFlags_AlwaysAutoResize;
        
        ImGui::Begin("Pause",NULL,window_flags);
        //centre window on screen
        ImGui::SetWindowPos(ImVec2((window->GetCentre().x - ImGui::GetWindowSize().x/2),(window->GetCentre().y - ImGui::GetWindowSize().y/2)));
        
        ImGui::Text("This is a pause menu!");
        if(ImGui::Button("Return"))
        {
            Pause = false;
        }
        
        ImGui::End();
    }
}
void Game::EarlyUpdate()
{
    if(r.getPosition().x >= window->GetSize().x-60)
    {
        direction *= -1;
    }
    if(r.getPosition().x <= 0)
    {
        direction *= -1;
    }
    
    
     r.move(direction, 0);
        
}
void Game::LateUpdate()
{
    
}
