//
//  DummyPhysics.hpp
//  WORMS
//
//  Created by Daniel Harvey on 27/02/2020.
//  Copyright © 2020 Daniel Harvey. All rights reserved.
//

#ifndef DummyPhysics_hpp
#define DummyPhysics_hpp
#include "PhysicsObject.hpp"

class Dummy : public PhysicsObject // Does nothing, shows a marker that helps with physics debug and test
{
public:
    
    
    Dummy(float x = 0.0f, float y = 0.0f) : PhysicsObject(x, y)
    {    }

    virtual void Draw(std::shared_ptr<Window> window, float fOffsetX, float fOffsetY)
    {
        window->DrawWireFrameModel(vecModel, px - fOffsetX, py - fOffsetY, atan2f(vy, vx));//, radius, FG_WHITE);
    }

    virtual int BounceDeathAction()
    {
        return 0; // Nothing, just fade
    }

private:
    static std::vector<std::pair<float, float>> vecModel;
};



#endif /* DummyPhysics_hpp */
