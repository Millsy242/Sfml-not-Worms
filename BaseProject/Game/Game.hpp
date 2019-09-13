//
//  Game.hpp
//  BaseProject
//
//  Created by Daniel Harvey on 15/06/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp
#include <SFML/Graphics.hpp>
#include "Window.hpp"


class Game
{
public:
    Game();
    ~Game(){};
    void Start();
    void Update();
    void EarlyUpdate();
    void LateUpdate();
    void Render();
    void Input();
    
private:
    Window window;
    sf::Clock c; 
    
    const sf::Time TimePerFrame = sf::seconds(1.f/60.f);
    sf::Time elapsedTime;
    sf::Time OverallPlayerLapTime;
    sf::Time mStatisticsUpdateTime;
    sf::Time TotalTime;
    sf::Time timeSinceLastUpdate;
};

#endif /* Game_hpp */
