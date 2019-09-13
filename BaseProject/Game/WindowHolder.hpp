//
//  Game.hpp
//  BaseProject
//
//  Created by Daniel Harvey on 15/06/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#ifndef WindowHolder_hpp
#define WindowHolder_hpp
#include "Base.hpp"
#include <SFML/Graphics.hpp>
#include "Window.hpp"

class WindowHolder : public Base
{
public:
    WindowHolder() ;
    ~WindowHolder(){};
    virtual void Start();
    virtual void Update();
    virtual void EarlyUpdate() = 0;
    virtual void LateUpdate() = 0;
    virtual void Render() = 0;
    virtual void Input() = 0;
    virtual void UI() = 0;
    virtual void Exit();
    void Stats();
    
protected:
    Window window;
    
private:
    sf::Clock c; 
    
    const sf::Time TimePerFrame = sf::seconds(1.f/60.f);
    sf::Time elapsedTime;
    sf::Time OverallPlayerLapTime;
    sf::Time mStatisticsUpdateTime;
    sf::Time TotalTime;
    sf::Time timeSinceLastUpdate;
};

#endif /* WindowHolder_hpp */

/*
 Thoughts:
 It could be worth having another class or even classes which this inherits from
 perhaps containing Update + UI + Render + Start + Exit + Input
 This might be a good framework to build from and be easier to manage!
 */
