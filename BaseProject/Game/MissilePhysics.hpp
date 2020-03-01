//
//  MissilePhysics.hpp
//  WORMS
//
//  Created by Daniel Harvey on 27/02/2020.
//  Copyright © 2020 Daniel Harvey. All rights reserved.
//

#ifndef MissilePhysics_hpp
#define MissilePhysics_hpp
#include "PhysicsObject.hpp"

class Missile : public PhysicsObject // A projectile weapon
{
public:
    Missile(float x = 0.0f, float y = 0.0f, float _vx = 0.0f, float _vy = 0.0f) : PhysicsObject(x, y)
    {
        radius = 2.5f;
        fFriction = 0.5f;
        vx = _vx;
        vy = _vy;
        bDead = false;
        nBounceBeforeDeath = 1;
    }
    virtual void Draw(std::shared_ptr<Window> window, float fOffsetX, float fOffsetY)
    {
        window->DrawWireFrameModel(vecModel, px - fOffsetX, py - fOffsetY, atan2f(vy, vx));//, radius, FG_WHITE);
    }


    virtual int BounceDeathAction()
    {
        return 40; // Explode Big
    }

private:
    static std::vector<std::pair<float, float>> vecModel;
};


#endif /* MissilePhysics_hpp */
