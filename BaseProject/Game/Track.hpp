//
//  Track.hpp
//  BaseProject
//
//  Created by Daniel Harvey on 15/09/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#ifndef Track_hpp
#define Track_hpp
#include "Entity.hpp"
#include "mySpline.hpp"
#include <stdio.h>
#include "SelbaWard.hpp"
class Track : public Entity
{
public:
    Track(){};
    ~Track(){};
    
    void Start() override;
    void LoadTexture(std::string filepath) override;
    void EntityUpdate() override;
    void Render(Window *window) override;
    void Input(sf::Event event) override;
    void Exit() override;
    
     
    sf::Sprite temp;
    void CreateTrackOutline(); 
    
    sf::Vector2f GetStart();
    
    bool LoadTrackFromFile(std::string filepath, sf::Vector2u ScreenSize);
    sf::Color getPixel(sf::Vector2f point);
    
    int getStartNode()
    {
        return StartNode;
    }
    
    mySpline CSpline,LSpline,RSpline, RacingLine;
    
private:
    int StartNode,EndNode,Sector1,Sector2,Sector3,numnodes,Width,Height;
    float TrackWidth;
    bool Loaded = false;
    
    float scaleX{1}, scaleY{1};
    
    sf::Texture trackedge;
    
    int iteration = 0;
    
    float fDisplacement[50];
    
    bool curve{false}, distance{true};
};

#endif /* Track_hpp */


