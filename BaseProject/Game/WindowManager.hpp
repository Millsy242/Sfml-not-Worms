//
//  WindowManager.hpp
//  BaseProject
//
//  Created by Daniel Harvey on 17/10/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#ifndef WindowManager_hpp
#define WindowManager_hpp
#include "Base.hpp"
#include <SFML/Graphics.hpp>
#include "Window.hpp"
#include "Game.hpp"
#include "Menu.hpp"

class WindowManager : public Base
{
public:
    WindowManager(){};
    ~WindowManager(){};
    
    void Start() override;
    void Update() override;
    void Exit() override;
    void Render(Window *window) override;
    void Input(sf::Event event) override;
    
private:
    std::unique_ptr<WindowHolder> currentWindow;
};

#endif /* WindowManager_hpp */
