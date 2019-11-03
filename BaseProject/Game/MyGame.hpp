//
//  MyGame.hpp
//  BaseProject
//
//  Created by Daniel Harvey on 03/11/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#ifndef MyGame_hpp
#define MyGame_hpp

#include <stdio.h>
#include "Game.hpp"

class MyGame : public Game
{
    void Start() override;
    void Input(sf::Event e) override;
    void Render(Window *window) override;
    void UI() override;
    void EarlyUpdate() override;
    void LateUpdate() override;
};

#endif /* MyGame_hpp */
