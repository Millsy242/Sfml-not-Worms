//
//  WindowManager.cpp
//  BaseProject
//
//  Created by Daniel Harvey on 17/10/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#include "WindowManager.hpp"
#include <iostream>
void WindowManager::Start()
{
    window.Start(" ");
    Settings.Setup();
    ChangeWindow(windowType::eMenu);
}
void WindowManager::Update()
{
    while(currentWindow->Continue)
    {
        Settings.Setup();
        currentWindow->Update();
        if(currentWindow->Continue)
        {
            if(CurrentWindowType == windowType::eMenu)
                ChangeWindow(windowType::eGame);
            else if(CurrentWindowType == windowType::eGame)
                ChangeWindow(windowType::eMenu);
        }
    }
    log << "Exiting";
}
void WindowManager::Exit()
{
    currentWindow->Exit();
}
void WindowManager::Render(Window *window)
{
    
}
void WindowManager::Input(sf::Event event)
{

}
void WindowManager::ChangeWindow(windowType wt)
{
    if(CurrentWindowType != wt)
    {
        CurrentWindowType = wt;
        switch (wt)
        {
            case windowType::eGame:
                window.SetSize(Settings.GameSize);
                currentWindow = std::make_shared<Game>(&log,&Settings);
                log << "Changing to Game";
                break;
            case windowType::eMenu:
                window.SetSize(Settings.MenuSize);
                currentWindow = std::make_shared<Menu>(&log,&Settings);
                log << "Changing to Menu";
                break;
            default:
                break;
        }
        currentWindow->GiveWindow(&window);
        currentWindow->Start();
    }
}
