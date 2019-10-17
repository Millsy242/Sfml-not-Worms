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

#include "Window.hpp"

class WindowHolder : public Base
{
public:
    WindowHolder() ;
    virtual ~WindowHolder(){};
    virtual void Start();
    virtual void Update();
    virtual void EarlyUpdate() = 0;
    virtual void LateUpdate() = 0;
    virtual void Render(Window *window) = 0;
    virtual void Input(sf::Event e) = 0;
    virtual void UI() = 0;
    virtual void Exit();
    void Stats();
    void GiveWindow(Window *w);
    
protected:

   bool Active = true;
    Window *window = nullptr;
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

