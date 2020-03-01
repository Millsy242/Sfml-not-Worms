//
//  WormPhysics.hpp
//  WORMS
//
//  Created by Daniel Harvey on 27/02/2020.
//  Copyright © 2020 Daniel Harvey. All rights reserved.
//

#ifndef WormPhysics_hpp
#define WormPhysics_hpp
#include "PhysicsObject.hpp"


class Worm : public PhysicsObject // A unit, or worm
{
public:
    Worm(float x = 0.0f, float y = 0.0f) : PhysicsObject(x, y)
    {
        radius = 3.5f;
        fFriction = 0.2f;
        bDead = false;
        nBounceBeforeDeath = -1;

        // load sprite data from sprite file
      //  if (sprWorm == nullptr)
         //   sprWorm = new olcSprite(L"worms.spr");
    }

   virtual void Draw(std::shared_ptr<Window> window, float fOffsetX, float fOffsetY)
    {
      //  engine->DrawPartialSprite(px - fOffsetX - radius, py - fOffsetY - radius, sprWorm, 0, 0, 8, 8);
    }

    virtual int BounceDeathAction()
    {
        return 0; // Nothing
    }

private:
   // static olcSprite *sprWorm;
};

#endif /* WormPhysics_hpp */
