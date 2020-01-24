//
//  MyMenu.hpp
//  BaseProject
//
//  Created by Daniel Harvey on 03/11/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#ifndef MyMenu_hpp
#define MyMenu_hpp

#include <stdio.h>
#include "Menu.hpp"

class MyMenu : public Menu
{
public:
    MyMenu(ige::FileLogger *LOG,SettingsManager *SM);
    
    void GameSettingsMenu() override;
    void GameSettingsMenuTWO() override;
    void Input(std::queue<sf::Event> &events) override;
    void Render(Window *window) override;
    void FixedUpdate(float dt) override;
    void EarlyUpdate() override;
    void LateUpdate() override;
    
private:
};

#endif /* MyMenu_hpp */
