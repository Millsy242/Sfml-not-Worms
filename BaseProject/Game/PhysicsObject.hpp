//
//  PhysicsObject.hpp
//  WORMS
//
//  Created by Daniel Harvey on 27/02/2020.
//  Copyright © 2020 Daniel Harvey. All rights reserved.
//

#ifndef PhysicsObject_hpp
#define PhysicsObject_hpp

#include "Window.hpp"

class PhysicsObject
{
public:
    virtual ~PhysicsObject() = default;
    
    float px = 0.0f; // Position
    float py = 0.0f;
    float vx = 0.0f; // Velocity
    float vy = 0.0f;
    float ax = 0.0f; // Acceleration
    float ay = 0.0f;

    float radius = 4.0f;    // Bounding circle for collision
    bool bStable = false;    // Has object stopped moving
    float fFriction = 0.8f;    // Actually, a dampening factor is a more accurate name

    int nBounceBeforeDeath = -1;    // How many time object can bounce before death
                                    // -1 = infinite
    bool bDead = false;        // Flag to indicate object should be removed

    PhysicsObject(float x = 0.0f, float y = 0.0f)
    {
        px = x;
        py = y;
    }

    // Make class abstract
    virtual void Draw(std::shared_ptr<Window> window, float fOffsetX, float fOffsetY) = 0;
    virtual int BounceDeathAction() = 0;
};

#endif /* PhysicsObject_hpp */
