//
//  Menu.cpp
//  BaseProject
//
//  Created by Daniel Harvey on 13/09/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#include "Menu.hpp"
#include <iostream>
 Menu::Menu() 
{
    
}

void Menu::Start()
{
        Active = true;
}
void Menu::Input(sf::Event e)
{

}
void Menu::Render(Window *window)
{
    window->BeginDraw(sf::Color::Blue);
    
    window->EndDraw();
}
void Menu::UI()
{
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
    
}
void Menu::LateUpdate()
{
    
}
