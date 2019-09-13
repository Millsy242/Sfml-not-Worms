//
//  Entity.hpp
//  BaseProject
//
//  Created by Daniel Harvey on 13/09/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp
#include "Base.hpp"
#include "Window.hpp"
#include <SFML/Graphics.hpp>
#include <stdio.h>

class Entity : public Base
{
public:
    Entity();
    ~Entity();
    
    virtual void Start() = 0;
    virtual void Update() = 0;
    virtual void Render(Window *window) = 0;
    virtual void Input(sf::Event event) = 0;
    virtual void Exit() = 0; 
};

#endif /* Entity_hpp */
