//
//  Car.cpp
//  BaseProject
//
//  Created by Daniel Harvey on 17/09/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#include "Car.hpp"
#include <iostream>
void Car::Start()
{
    
}
void Car::giveRacingLineSpline(mySpline *RacingLine_, int startpoint)
{
    RacingLine = RacingLine_;
    EntitySprite.setScale({3,3});
    EntitySprite.setOrigin(EntitySprite.getLocalBounds().width/2, EntitySprite.getLocalBounds().height/2);
    
    start = startpoint;
    fmarker = start;
}
void Car::EntityUpdate()
{
    

}
void Car::Render(Window *window)
{
    
    
    fmarker += 1.1f * 0.016;
    // if (fmarker > (float)RacingLine->points.size())
    //   fmarker = 0;
    
    if (fmarker >= (float)RacingLine->points.size())
        fmarker -= (float)RacingLine->points.size();
    
    if (fmarker < 0.0f)
        fmarker += (float)RacingLine->points.size();
    
    
    SetPosition(RacingLine->GetSplinePoint(fmarker));
    
    float rot = atan2(RacingLine->GetSplineGradient( fmarker).y, (RacingLine->GetSplineGradient(fmarker).x));
   // EntitySprite.rotate(tanf(rot));
    //EntitySprite.setRotation(sinf(rot));
    
    float fOffset = fmarker;// RacingLine->GetNormalisedOffset(fmarker);
    sf::Vector2f p1 = RacingLine->GetSplinePoint(fOffset);
    sf::Vector2f g1 = RacingLine->GetSplineGradient(fOffset);
    float r = atan2(-g1.y, g1.x);
    float len = 50.f;
    
    
    
    sf::Vector2f start = {len * sin(r) + p1.x, len * cos(r) + p1.y};
    sf::Vector2f end = {-len * sin(r) + p1.x, -len * cos(r) + p1.y};
    sw::Line myline(start,end,5.f);
    
    EntitySprite.setRotation(sf::getAngleBetween(end, start));
    
    if(Active)
        window->draw(EntitySprite);
    
    window->draw(myline);
}
void Car::Input(sf::Event event)
{
    /*
     D = false;B = false;L = false;R = false;
    if(event.type == sf::Event::KeyPressed )
    {
        if(event.key.code == sf::Keyboard::Left)
        {
            L = 1;
        }
        if(event.key.code == sf::Keyboard::Right)
        {
            R = 1;
        }
        if(event.key.code == sf::Keyboard::Space)
        {
            D = 1;
        }
        if( event.key.code == sf::Keyboard::Down)
        {
            B = 1;
        }
    }
  //
   
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        R=1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        B=1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        L=1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        D=1;
    }
     */
     //MoveCar(D,R,L,B);
}
void Car::Exit()
{
    
}
void Car::MoveCar(bool Drive,bool Right, bool Left, bool Brake)
{
    float turnSpeed_temp = turnSpeed * (1-(speed/maxSpeed));
    
    if(speed > 0)
    {
        if(Right || Left)
        {
            if(speed > 3)
                speed-=(acc*0.75);
            speed-=0.0001; // some speed is scrubbed off when turning.
            
            if(Left)
            {
                turnSpeed_temp = -turnSpeed_temp;
                EntitySprite.rotate(turnSpeed_temp);
            }
            else if(Right)
            {
                EntitySprite.rotate(turnSpeed_temp);
            }
        }
        if(Brake)
        {
            speed -= drag;
            speed -= brakepower;
        }
    }
    if(Drive)
    {
        if (speed<maxSpeed)
        {
            speed += acc;
        }
    }
    else
    {
        if (speed - drag > 0)
        {
            speed -= drag;
        }
        else if (speed + drag < 0)
        {
            speed += drag ;
        }
        else
        {
            speed = 0;
        }
    }
    if(Brake)
    {
        speed -= drag;
        speed -= brakepower;
    }
    if(speed < 0)
    {
        speed = 0; //make sure car doesn't go backwards.
    }
    
    sf::Vector2f oldVec = movementVec;
    
    sf::Transform t;
    t.rotate(EntitySprite.getRotation());
    movementVec = t.transformPoint(forwardVec);
    //calc the dot product so any rotation reduces the
    //current speed - gives the impression of wheel spin
    //when accelerating after a tight turn
    speed *= oldVec * movementVec;
   
    SetPosition(sf::Vector2f(GetPosition().x + (movementVec.x * speed),GetPosition().y + (movementVec.y * speed)));    
}
void Car::LoadFromFile(std::string Filepath)
{
    std::string line;

    std::ifstream myfile(Filepath);
    bool exit = false;
    int i = 0;
    if (myfile.is_open())
    {
        while ( getline (myfile,line) && !exit)
        {
            switch(i)
            {
                case(0):
                    break;
                case(1):
                    maxSpeed = std::stof(line);
                    break;
                case(2):
                    acc = std::stof(line) ;
                    break;
                case(3):
                    drag = std::stof(line);
                    break;
                case(4):
                    brakepower = std::stof(line) ;
                    break;
                case(5):
                    turnSpeed = std::stof(line) ;
                    break;
                case(6):
                    offTrackSpeed = std::stof(line);
                    break;
                case(7):
                    break;
                case(8):
                    exit = true;
                    break;
                default:
                    break;
            }
            i++;
        }
        myfile.close();
    }

}





