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
    myRect(int l, int t, int r, int b) : left{l},right{r},top{t},base{b},width{r-l},height{b-t},area{width * height} {};
    myRect(sf::IntRect ir)             : left{ir.left},right{ir.left + ir.width},top{ir.top},base{ir.top + ir.height},width{ir.width},height{ir.height},area{width * height}{};
    myRect(int w, int h)               : left{0},right{w},top{0},base{h},width{w},height{h},area{width * height}{};
    myRect()                           : left{0},right{1},top{0},base{1},width{1},height{1},area{width*height} {};
    
    void move(int x, int y)
    {
        left  += x;
        right += x;
        top   += y;
        base  += y;
    };
    
    void SetPosition(int x, int y)
    {
        move(x - left, y - top);
    }
    
    int left{0},right{0},top{0},base{0},width{0},height{0},area{0};
    
};

#endif /* Rect_hpp */
