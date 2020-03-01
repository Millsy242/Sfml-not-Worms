//
//  Map.hpp
//  WORMS
//
//  Created by Daniel Harvey on 29/02/2020.
//  Copyright © 2020 Daniel Harvey. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp
#include <SFML/Graphics.hpp>
#include "Window.hpp"
#include <thread>
#include <iostream>

class Map
{
public:
    Map();
    Map(int Width,int Height);
    ~Map();
    
    void CreateMap();
    void Render(std::shared_ptr<Window> window, int CamX, int CamY);
    
    unsigned char getFromMap(int x, int y);
    void SetInMap(int x, int y, unsigned char value);
    
    int getWidth();
    int getHeight();
    
    unsigned char *map = nullptr;
    
private:
    void PerlinNoise1D(int nCount, float *fSeed, int nOctaves, float fBias, float *fOutput);
    int nMapHeight{512},nMapWidth{1024};
    
    int tilesize = 1;
    
    
    
    sf::VertexArray Mapbuffer;
    int sizeOfBuffer{0};
};

#endif /* Map_hpp */
