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
    window->BeginDraw(sf::Color::Blue);
    
    window->EndDraw();
}
void Menu::UI()
{
    *log << "Menu UI";
    ImGui::Begin("Menu");
    if(ImGui::Button("change to Game"))
    {
        std::cout<<"stop menu\n";
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
