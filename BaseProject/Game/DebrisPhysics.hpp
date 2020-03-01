//
//  DebrisPhysics.hpp
//  WORMS
//
//  Created by Daniel Harvey on 27/02/2020.
//  Copyright © 2020 Daniel Harvey. All rights reserved.
//

#ifndef DebrisPhysics_hpp
#define DebrisPhysics_hpp

#include "PhysicsObject.hpp"

class Debris : public PhysicsObject // a small rock that bounces
{
public:
    Debris(float x = 0.0f, float y = 0.0f) : PhysicsObject(x, y)
    {
        // Set velocity to random direction and size for "boom" effect
        vx = 10.0f * cosf(((float)rand() / (float)RAND_MAX) * 2.0f * 3.14159f);
        vy = 10.0f * sinf(((float)rand() / (float)RAND_MAX) * 2.0f * 3.14159f);
        radius = 1.0f;
        fFriction = 0.8f;
        nBounceBeforeDeath = 5; // After 5 bounces, dispose
    }
    
    virtual void Draw(std::shared_ptr<Window> window, float fOffsetX, float fOffsetY)
    {
        window->DrawWireFrameModel(vecModel, px - fOffsetX, py - fOffsetY, atan2f(vy, vx),radius,sf::Color::Black);
    }
    
    virtual int BounceDeathAction()
    {
        return 0; // Nothing, just fade
    }

private:
    static std::vector<std::pair<float, float>> vecModel;
};

#endif /* DebrisPhysics_hpp */
