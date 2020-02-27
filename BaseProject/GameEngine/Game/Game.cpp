//
//  Game.cpp
//  BaseProject
//
//  Created by Daniel Harvey on 13/09/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//
#include "Game.hpp"
#include <iostream>

Game::Game(std::shared_ptr<ige::FileLogger> LOG,std::shared_ptr<SettingsManager> SM)
{
    log = LOG;
    settings = SM;
    ResourceHolder::get().textures.add("Game Icons/Debug");
    ResourceHolder::get().textures.add("Game Icons/Exit");
    ResourceHolder::get().textures.add("Game Icons/Pause");
    ResourceHolder::get().textures.add("Game Icons/Settings");
    
    Active = true;
}
 Game::~Game()
{

};
void Game::addObject(Base *b)
{
    bool add = true;
    for(int i{0}; i < ObjectVector.size(); i++)
    {
        if(ObjectVector[i] == b)
        {
            add = false;
            break;
        }
    }
    if(add)
        ObjectVector.push_back(b);
}
Base* Game::getObject(unsigned int pos)
{
    if(pos < ObjectVector.size())
    {
        return ObjectVector[pos];
    }
    return nullptr;
}

void Game::Stats()
{
    WindowHolder::Stats();
    
    if(Debug)
    {
        if(DebugMemoryEditer)
        {
            if(!ObjectVector.empty() && selected >= 0 && selected < ObjectVector.size())
            {
                mem_edit.DrawWindow("Memory Editor", getObject(selected), sizeof(*getObject(selected)));
            }
            
            ImGui::Begin("Stats");
            ImGui::Text("selected: %i", selected);
            ImGui::End();
        }
    }
}
void Game::DebugRender(std::shared_ptr<Window> window)
{
    for(int i{0}; i<ObjectVector.size();i++)
    {
        ObjectVector[i]->Render(window);
    }
}
void Game::Start()
{
    *log << "Game Start";
}
void Game::Input(std::queue<sf::Event> &events, float dt)
{
   *log << "Game Input";
}
void Game::Render(std::shared_ptr<Window> window)
{
    *log << "Game Render";
    window->BeginDraw(sf::Color(20,55,34));
    
    window->EndDraw();
}
void Game::UI()
{
    *log << "UI";
    GameUI();
}
void Game::EarlyUpdate()
{
    *log << "Game Early Update";

}
void Game::LateUpdate()
{
    *log << "Game Late Update";
}
void Game::FixedUpdate(float dt)
{
    *log << "Game Fixed Update";
}
void Game::SetGameArea(myRect R)
{
    GameArea = R;
    GameAreaShape.setSize(sf::Vector2f(GameArea.width,GameArea.height));
    GameAreaShape.setPosition(GameArea.left,GameArea.top);
}
void Game::GameUI()
{
    ImGuiWindowFlags window_flags = 0;
    window_flags |= ImGuiWindowFlags_NoMove;
    window_flags |= ImGuiWindowFlags_NoNav;
    window_flags |= ImGuiWindowFlags_NoCollapse;
    window_flags |= ImGuiWindowFlags_NoNavFocus;
    window_flags |= ImGuiWindowFlags_NoTitleBar;
    window_flags |= ImGuiWindowFlags_AlwaysAutoResize;
    window_flags |= ImGuiWindowFlags_NoBackground;
    
    ImGui::Begin("GameUI",NULL,window_flags);
    if(Pause)
    {
        *log << "Game Paused";
        //centre window on screen
        ImGui::SetWindowPos(ImVec2((window->GetCentre().x - ImGui::GetWindowSize().x/2),(window->GetCentre().y - ImGui::GetWindowSize().y/2)));
        
        ImGui::Text("PAUSED");
        if(ImGui::Button("Return"))
        {
            Pause = false;
        }
        if(ImGui::Button("Menu"))
        {
             Active = false;
        }
    }
    else
    {
        ImGui::SetWindowPos(ImVec2((window->GetCentre().x - ImGui::GetWindowSize().x/2),(window->GetSize().y - ImGui::GetWindowSize().y-50)));
        ImGui::SetCursorPos(ImVec2(5,5));
        if(ImGui::ImageButton(ResourceHolder::get().textures.get("Game Icons/Pause"), sf::Vector2f(20,20)))
        {
            Pause = true;
        }
        ImGui::SetCursorPos(ImVec2(35,5));
        if(ImGui::ImageButton(ResourceHolder::get().textures.get("Game Icons/Settings"), sf::Vector2f(20,20)))
        {
            Pause = true;
        }
        ImGui::SetCursorPos(ImVec2(65,5));
        if(ImGui::ImageButton(ResourceHolder::get().textures.get("Game Icons/Exit"), sf::Vector2f(20,20)))
        {
            Continue = false;
            Active = false;
        }
        ImGui::SetCursorPos(ImVec2(95,5));
        if(ImGui::ImageButton(ResourceHolder::get().textures.get("Game Icons/Debug"), sf::Vector2f(20,20)))
        {
            Debug = !Debug;
        }
    }
    ImGui::End();

    if(Debug)
    {
        ImGui::Begin("Debug Menu");
            ImGui::Checkbox("Metrics", &DebugMetrics);
            ImGui::Checkbox("User Guide", &DebugUserGuide);
            ImGui::Checkbox("Style Selector", &DebugStyleSel);
            ImGui::Checkbox("Style Editor", &DebugStyleEditer);
            ImGui::Checkbox("Memory Editor", &DebugMemoryEditer);
        ImGui::End();
    }
}
