//
//  MyMenu.cpp
//  BaseProject
//
//  Created by Daniel Harvey on 03/11/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#include "MyMenu.hpp"

MyMenu::MyMenu(std::shared_ptr<ige::FileLogger> LOG,std::shared_ptr<SettingsManager> SM) : Menu(LOG,SM)
{
    
}
void MyMenu::GameSettingsMenu()
{
    ImGui::Text("this is the Game Settings Menu!\nIt should be used for settings related to ingame variables. Such as car details, tracks etc");
}
void MyMenu::Input(std::queue<sf::Event> &events)
{
    *log << "Menu Input";
}
void MyMenu::Render(std::shared_ptr<Window> window)
{
    *log << "Menu Render";
    window->BeginDraw(sf::Color(40,45,55));
    
    window->EndDraw();
}
void MyMenu::EarlyUpdate()
{
    *log << "Menu Early Update";
}
void MyMenu::LateUpdate()
{
    *log << "Menu Late Update";
}
void MyMenu::FixedUpdate(float dt)
{
    *log << "Menu Fixed Update";
}
void MyMenu::GameSettingsMenuTWO()
{
    
}
