//
//  Menu.hpp
//  BaseProject
//
//  Created by Daniel Harvey on 13/09/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include "WindowHolder.hpp"
#include <stdio.h>

class Menu : public WindowHolder
{
public:
    Menu(ige::FileLogger *LOG,SettingsManager *SM);
    ~Menu(){};
        
    virtual void Start() override;
    virtual void Input(sf::Event e) override;
    virtual void Render(Window *window) override;
    virtual void UI() override;
    virtual void EarlyUpdate() override;
    virtual void LateUpdate() override;
    
private:
   virtual void StartScreen();
   virtual void ProgramSettingsMenu();
   virtual void GameSettingsMenu();
   sf::Texture StartTexture,SettingsTexture,ExitTexture;
};
#endif /* Menu_hpp */
