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
    
   // FlipTexture(true);
    
    EntitySprite.setOrigin(EntitySprite.getLocalBounds().width/2, EntitySprite.getLocalBounds().height-10);
    
    start = startpoint;
    fmarker = start;
}

void Car::EntityUpdate()
{
    /*
    fmarker -=speed * 0.0016; //+ or - depending on direction
        
    if (fmarker >= (float)RacingLine->points.size())
        fmarker -= (float)RacingLine->points.size();
    
    if (fmarker < 0.0f)
        fmarker += (float)RacingLine->points.size();
    
    float fOffset =  fmarker;//RacingLine->GetNormalisedOffset(fmarker);
    sf::Vector2f p1 = RacingLine->GetSplinePoint(fOffset);
    sf::Vector2f g1 = RacingLine->GetSplineGradient(fOffset);
    float r = atan2(-g1.y, g1.x);
    float len = 50.f;

    sf::Vector2f start = {len * sin(r) + p1.x, len * cos(r) + p1.y};
    sf::Vector2f end = {-len * sin(r) + p1.x, -len * cos(r) + p1.y};
    myline = sw::Line(start,end,5.f);
    */
    angle = sf::degToRad(EntitySprite.getRotation());
    
    float x{GetPosition().x},y{GetPosition().y},tx{RacingLine->GetSplinePoint(fmarker).x},ty{RacingLine->GetSplinePoint(fmarker).y};
    
    if ((x-tx)*(x-tx)+(y-ty)*(y-ty)<radius*radius)
    {
        fmarker=std::fmod(fmarker-0.25, RacingLine->points.size());
        if(fmarker < 0)
            fmarker = RacingLine->points.size() -1;
    }
    

    bool D_{1},B_{0},R_{0},L_{0};
    
    sf::Vector2f next = RacingLine->GetSplinePoint(fmarker);
    
    tx=next.x;
    ty=next.y;

    float beta = angle-atan2(tx-GetPosition().x,-ty+GetPosition().y);

    if (sin(beta) < 0)
    {
        R_ = true;
    }
    else
    {
        L_ = true;
    }

    MoveCar(D_,R_,L_,B_);

   //EntitySprite.setRotation(sf::radToDeg( angle));
}
void Car::Render(Window *window)
{
    ImGui::Begin("car");
    ImGui::SliderInt("radius", &radius, 1, 1000);
    ImGui::End();
    
    sf::CircleShape circle;
    circle.setRadius(radius);
    circle.setOutlineThickness(5);
    circle.setOutlineColor(sf::Color::White);
    circle.setFillColor(sf::Color::Transparent);
    circle.setOrigin(circle.getLocalBounds().width/2, circle.getLocalBounds().height/2);
    
    for(float t{0};t<RacingLine->points.size();t++)
    {
        circle.setPosition(RacingLine->GetSplinePoint(t));
        window->draw(circle);

    }
    
    if(Active)
        window->draw(EntitySprite);
    
    window->draw(myline);
}
void Car::Input(sf::Event event)
{
    
     D = false;B = false;L = false;R = false;
    /*
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
  */
   
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
          //  speed-=0.0001; // some speed is scrubbed off when turning.
            
            if(Left)
            {
                EntitySprite.rotate(-turnSpeed_temp);
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
    if(offTrack && speed>offTrackSpeed)
    {
        speed--;
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





