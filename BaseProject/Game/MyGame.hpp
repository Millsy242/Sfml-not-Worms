//
//  MyGame.hpp
//  BaseProject
//
//  Created by Daniel Harvey on 03/11/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#ifndef MyGame_hpp
#define MyGame_hpp
#include <iostream>
#include <stdio.h>
#include "Game.hpp"
#include "SelbaWard.hpp"

class MyGame : public Game
{
public:
    MyGame(ige::FileLogger *LOG,SettingsManager *SM) ;
    void Start() override;
    void Input(std::queue<sf::Event> &events) override;
    void Render(Window *window) override;
    void UI() override;
    void EarlyUpdate() override;
    void LateUpdate() override;
    void FixedUpdate(float dt) override;
private:
    sw::Sprite3d spr;
    sf::Texture texture; 
};

#endif /* MyGame_hpp */
