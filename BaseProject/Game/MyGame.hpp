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
#include <list>
#include <array>
#include "Game.hpp"
#include "SelbaWard.hpp"
#include "PhysicsObject.hpp"
#include "Map.hpp"

class myBase : public Base
{
public:
    myBase(int a = 0){b=a;};
    void Start() {Base::Start();ClassName = "MYBASE";};
    
    int b;
};

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
    void Boom(float fWorldX,float fWorldY,float fRadius);
    Map map;
    float fCameraPosX = 0.0f;
    float fCameraPosY = 0.0f;

    std::list<std::unique_ptr<PhysicsObject>> listObjects;
};

#endif /* MyGame_hpp */
