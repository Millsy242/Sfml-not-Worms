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
    
    bool LoadTrackFromFile(std::string filepath);
    sf::Color getPixel(sf::Vector2f point);
    
private:
    int StartNode,EndNode,Sector1,Sector2,Sector3,numnodes;
    float TrackWidth;
    bool Loaded = false;
    mySpline CSpline,LSpline,RSpline;
};

#endif /* Track_hpp */


