//
//  WindowManager.cpp
//  BaseProject
//
//  Created by Daniel Harvey on 17/10/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#include "WindowManager.hpp"

void WindowManager::Start()
{
    currentWindow = std::make_unique<Menu>();
    currentWindow->Start();
}
void WindowManager::Update()
{
    currentWindow->Update();
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
