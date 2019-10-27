//
//  Menu.cpp
//  BaseProject
//
//  Created by Daniel Harvey on 13/09/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#include "Menu.hpp"
#include <iostream>
 Menu::Menu(ige::FileLogger *LOG)
{
    log = LOG;
}

void Menu::Start()
{
    *log << "Starting Menu";
        Active = true;
}
void Menu::Input(sf::Event e)
{
    *log << "Menu Input";
}
void Menu::Render(Window *window)
{
    *log << "Menu Render";
    window->BeginDraw(sf::Color(40,45,55));
    
    window->EndDraw();
}
void Menu::UI()
{
    *log << "Menu UI";
    ImGuiWindowFlags window_flags = 0;
    window_flags |= ImGuiWindowFlags_NoMove;
    window_flags |= ImGuiWindowFlags_NoNav;
    window_flags |= ImGuiWindowFlags_NoCollapse;
    window_flags |= ImGuiWindowFlags_NoNavFocus;
    window_flags |= ImGuiWindowFlags_NoTitleBar;
    window_flags |= ImGuiWindowFlags_NoBackground;
    
    ImGui::Begin("Menu",NULL,window_flags);
    ImGui::SetWindowSize(ImVec2(window->GetSize()));
    ImGui::SetWindowPos(ImVec2(0,0));
    ImGui::SetCursorPos(ImVec2(150,50));
    //Look up how to move buttons into centre
    //possibly just specify size of buttons using button images
    if(ImGui::Button("Start"))
    {
         Active = false;
    }
    ImGui::SetCursorPos(ImVec2(150,100));
    if(ImGui::Button("Settings"))
    {
         //settings menu
    }
    ImGui::SetCursorPos(ImVec2(150,150));
    if(ImGui::Button("Exit"))
    {
        Continue = false;
        Active = false;
    }
    ImGui::End();
    

    
}
void Menu::EarlyUpdate()
{
    *log << "Menu Early Update";
}
void Menu::LateUpdate()
{
    *log << "Menu Late Update";
}
