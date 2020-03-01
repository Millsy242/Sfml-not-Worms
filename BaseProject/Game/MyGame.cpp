//
//  MyGame.cpp
//  BaseProject
//
//  Created by Daniel Harvey on 03/11/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#include "MyGame.hpp"
#include "DummyPhysics.hpp"
#include "DebrisPhysics.hpp"
#include "MissilePhysics.hpp"

MyGame::MyGame(std::shared_ptr<ige::FileLogger> LOG,std::shared_ptr<SettingsManager> SM) : Game(LOG, SM)
{
    
}
void MyGame::Start()
{
    *log << "Game Start";
    
    map = Map(1024,1024);
    map.CreateMap();
}
void MyGame::Input(std::queue<sf::Event> &events, float dt)
{
   *log << "Game Input";

    // Mouse Edge Map Scroll
    //Change from window boundaries to game area boundaries!
    float fMapScrollSpeed = 400.0f;
    if(window->GetMouse().x < 5 || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        fCameraPosX -= fMapScrollSpeed * dt;
    if (window->GetMouse().x > window->GetSize().x - 5 || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        fCameraPosX += fMapScrollSpeed * dt;
    if (window->GetMouse().y < 5 || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        fCameraPosY -= fMapScrollSpeed * dt;
    if (window->GetMouse().y > window->GetSize().y - 5 || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        fCameraPosY += fMapScrollSpeed * dt;

    // Clamp map boundaries
    if (fCameraPosX < 0)
        fCameraPosX = 0;
    if (fCameraPosX >= map.getWidth() - window->GetSize().x)
        fCameraPosX = map.getWidth() - window->GetSize().x;
    if (fCameraPosY < 0)
        fCameraPosY = 0;
    if (fCameraPosY >= map.getHeight() - window->GetSize().y)
        fCameraPosY = map.getHeight() - window->GetSize().y;
    
    ImGui::Begin("Stats");
    ImGui::Text("camera: %f,%f ", fCameraPosX,fCameraPosY);
    ImGui::End();
}
void MyGame::Render(std::shared_ptr<Window> window)
{
    *log << "Game Render";
    window->BeginDraw(sf::Color::Magenta);

    
    map.Render(window,(int)fCameraPosX,(int)fCameraPosY);
     
    for(auto &p : listObjects)
        p->Draw(window, fCameraPosX, fCameraPosY);
    
    Game::DebugRender(window);
    window->EndDraw();
}
void MyGame::UI()
{
    *log << "UI";
    Game::GameUI();
    ImGui::Begin("WormsDebug");
    if(ImGui::Button("create new map"))
    {
        map.CreateMap();
    }
    if(ImGui::Button("dummy"))
    {
        listObjects.push_back(std::unique_ptr<Dummy>(new Dummy(window->GetMouse().x + fCameraPosX,window->GetMouse().y + fCameraPosY)));
    }
    if(ImGui::Button("debris"))
    {
        for(int i{0};i<20;i++)
        {
            listObjects.push_back(std::unique_ptr<Debris>(new Debris(window->GetMouse().x + fCameraPosX,window->GetMouse().y + fCameraPosY)));
        }
    }
    if(ImGui::Button("explosion"))
    {
        Boom(window->GetMouse().x + fCameraPosX,window->GetMouse().y + fCameraPosY, 10.0f);
    }
    if(ImGui::Button("Misile"))
    {
        listObjects.push_back(std::unique_ptr<Missile>(new Missile(window->GetMouse().x + fCameraPosX,window->GetMouse().y + fCameraPosY)));
    }
    
    ImGui::End();
}
void MyGame::EarlyUpdate()
{
    *log << "Game Early Update";
}
void MyGame::LateUpdate()
{
    *log << "Game Late Update";
}
void MyGame::FixedUpdate(float dt)
{
    *log << "Game Fixed Update";
    
    // Update physics of all physical objects
    for(int i{0};i<10;i++)
    {
       for (auto &p : listObjects)
       {
           // Apply Gravity
           p->ay += 2.0f;

           // Update Velocity
           p->vx += p->ax * dt;
           p->vy += p->ay * dt;

           // Update Position
           float fPotentialX = p->px + p->vx * dt;
           float fPotentialY = p->py + p->vy * dt;

           // Reset Acceleration
           p->ax = 0.0f;
           p->ay = 0.0f;
           p->bStable = false;

           // Collision Check With Map
           float fAngle = atan2f(p->vy, p->vx);
           float fResponseX = 0;
           float fResponseY = 0;
           bool bCollision = false;

          // Iterate through semicircle of objects radius rotated to direction of travel
          for (float r = fAngle - 3.14159f / 2.0f; r < fAngle + 3.14159f / 2.0f; r += 3.14159f / 8.0f)
          {
              // Calculate test point on circumference of circle
              float fTestPosX = (p->radius) * cosf(r) + fPotentialX ;
              float fTestPosY = (p->radius) * sinf(r) + fPotentialY ;

              // Constrain to test within map boundary
              if (fTestPosX >= map.getWidth())
                  fTestPosX = map.getWidth() - 1;
              if (fTestPosY >= map.getHeight())
                  fTestPosY = map.getHeight() - 1;
              if (fTestPosX < 0)
                  fTestPosX = 0;
              if (fTestPosY < 0)
                  fTestPosY = 0;

              // Test if any points on semicircle intersect with terrain
              if (map.getFromMap(fTestPosX, fTestPosY)  != 0)
              {
                  // Accumulate collision points to give an escape response vector
                  // Effectively, normal to the areas of contact
                  fResponseX += fPotentialX - fTestPosX;
                  fResponseY += fPotentialY - fTestPosY;
                  bCollision = true;
              }
          }
      

          // Calculate magnitudes of response and velocity vectors
          float fMagVelocity = sqrtf(p->vx*p->vx + p->vy*p->vy);
          float fMagResponse = sqrtf(fResponseX*fResponseX + fResponseY*fResponseY);

          // Collision occurred
          if (bCollision)
          {
              // Force object to be stable, this stops the object penetrating the terrain
              p->bStable = true;
              
              // Calculate reflection vector of objects velocity vector, using response vector as normal
              float dot = p->vx * (fResponseX / fMagResponse) + p->vy * (fResponseY / fMagResponse);
              
              // Use friction coefficient to dampen response (approximating energy loss)
              p->vx = p->fFriction * (-2.0f * dot * (fResponseX / fMagResponse) + p->vx);
              p->vy = p->fFriction * (-2.0f * dot * (fResponseY / fMagResponse) + p->vy);

              //Some objects will "die" after several bounces
              if (p->nBounceBeforeDeath > 0)
              {
                  p->nBounceBeforeDeath--;
                  p->bDead = p->nBounceBeforeDeath == 0;

                  // If object died, work out what to do next
                  if (p->bDead)
                  {
                      // Action upon object death
                      // = 0 Nothing
                      // > 0 Explosion
                      int nResponse = p->BounceDeathAction();
                      if (nResponse > 0)
                          Boom(p->px, p->py, nResponse);
                  }
              }

          }
          else
          {
              // No collision so update objects position
              p->px = fPotentialX;
              p->py = fPotentialY;
          }

          // Turn off movement when tiny
          if (fMagVelocity < 0.1f)
              p->bStable = true;
      }
    
      // Remove dead objects from the list, so they are not processed further. As the object
      // is a unique pointer, it will go out of scope too, deleting the object automatically. Nice :-)
      listObjects.remove_if([](std::unique_ptr<PhysicsObject> &o) {return o->bDead; });
    }

}



// Taken from Perlin Noise Video https://youtu.be/6-0UaeJBumA

 void MyGame::Boom(float fWorldX,float fWorldY,float fRadius)
{
    auto CircleBresenham = [&](int xc, int yc, int r)
    {
        // Taken from wikipedia
        int x = 0;
        int y = r;
        int p = 3 - 2 * r;
        if (!r) return;

        auto drawline = [&](int sx, int ex, int ny)
        {
            for (int i = sx; i < ex; i++)
            {
                if (ny >= 0 && ny < map.getHeight() && i >= 0 && i < map.getWidth())
                {
                    map.SetInMap(i, ny, 0);
                }
            }
        };

        while (y >= x)
        {
            // Modified to draw scan-lines instead of edges
            drawline(xc - x, xc + x, yc - y);
            drawline(xc - y, xc + y, yc - x);
            drawline(xc - x, xc + x, yc + y);
            drawline(xc - y, xc + y, yc + x);
            if (p < 0) p += 4 * x++ + 6;
            else p += 4 * (x++ - y--) + 10;
        }
    };

    // Erase Terrain to form crater
    CircleBresenham(fWorldX, fWorldY, fRadius);

    // Shockwave other entities in range
    for (auto &p : listObjects)
    {
        // Work out distance between explosion origin and object
        float dx = p->px - fWorldX;
        float dy = p->py - fWorldY;
        float fDist = sqrt(dx*dx + dy*dy);
        if (fDist < 0.0001f) fDist = 0.0001f;

        // If within blast radius
        if (fDist < fRadius)
        {
            // Set velocity proportional and away from boom origin
            p->vx = (dx / fDist) * fRadius;
            p->vy = (dy / fDist) * fRadius;
            p->bStable = false;
        }
    }

    // Launch debris proportional to blast size
    for (int i = 0; i < (int)fRadius; i++)
        listObjects.push_back(std::unique_ptr<Debris>(new Debris(fWorldX,fWorldY)));

}
