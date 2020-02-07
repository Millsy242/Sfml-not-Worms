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
        MyGame(std::shared_ptr<ige::FileLogger> LOG, std::shared_ptr<SettingsManager> SM) ;
        void Start() override;
        void Input(std::queue<sf::Event> &events, float dt) override;
        void Render(std::shared_ptr<Window> window) override;
        void UI() override;
        void EarlyUpdate() override;
        void LateUpdate() override;
        void FixedUpdate(float dt) override;
    private:
    sf::Texture t;
    sf::Sprite s;
    float vx{0}, vy{0};
};

#endif /* MyGame_hpp */
