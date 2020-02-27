//
//  Base.hpp
//  BaseProject
//
//  Created by Daniel Harvey on 13/09/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#ifndef Base_hpp
#define Base_hpp
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Window.hpp"
#include <queue>
#include "Rect.hpp"
#include <iostream>

class Base
{
public:
    virtual void Start();
    virtual void Update();
    virtual void FixedUpdate(float dt);
    virtual void Exit();
    virtual void Render(std::shared_ptr<Window> window);
    virtual void Input(std::queue<sf::Event> &events, float dt);
    virtual void UI();
    virtual void DebugUI(int i);
    void DebugSelected(bool sel);
protected:
    std::string ClassName = "BaseClass";
    myRect Bounds;
    sf::Vector2f Position = {80,80};
    sf::Vector2f Size = {300,300};
    bool Renderable = false;
private:
    bool drawRect = false;
    bool Selected = false;
};

#endif /* Base_hpp */
