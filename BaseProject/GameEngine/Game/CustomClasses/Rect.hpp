//
//  Rect.hpp
//  GameEngineSFML
//
//  Created by Daniel Harvey on 06/02/2020.
//  Copyright © 2020 Daniel Harvey. All rights reserved.
//

#ifndef Rect_hpp
#define Rect_hpp

#include <SFML/Graphics/Rect.hpp>

struct myRect
{
    myRect(float l, float t, float r, float b) : left{l},right{r},top{t},base{b},width{r-l},height{b-t},area{width * height} {};
    myRect(sf::IntRect ir)             : left{(float)ir.left},right{(float)ir.left + (float)ir.width},top{(float)ir.top},base{(float)ir.top + (float)ir.height},width{(float)ir.width},height{(float)ir.height},area{width * height}{};
    myRect(float w, float h)               : left{0},right{w},top{0},base{h},width{w},height{h},area{width * height}{};
    myRect()                           : left{0},right{1},top{0},base{1},width{1},height{1},area{width*height} {};
    
    void move(float x, float y)
    {
        left  += x;
        right += x;
        top   += y;
        base  += y;
    };
    
    void SetPosition(float x, float y)
    {
        move(x - left, y - top);
    }
    
    float left{0},right{0},top{0},base{0},width{0},height{0},area{0};
    
};

#endif /* Rect_hpp */
