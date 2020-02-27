//
//  Animation.hpp
//  GameEngineSFML
//
//  Created by Daniel Harvey on 18/02/2020.
//  Copyright © 2020 Daniel Harvey. All rights reserved.
//

#ifndef Animation_hpp
#define Animation_hpp

#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
    public:
        struct Frame
        {
            Frame(const sf::IntRect& bnds, sf::Time dly)
            :   bounds  (bnds)
            ,   delay   (dly) {}

            sf::IntRect bounds; //The area in a texture of the frame
            sf::Time    delay;  //Time delay to next frame
        };

        Animation(unsigned frameWidth, unsigned frameHeight);

        void addFrame(unsigned index, sf::Time delay);

        const sf::IntRect& getFrame();

    private:
        sf::Clock m_timer;              //Timer for progressing the animation
        sf::Time m_overlappedTime;      //Overlapped time from last getFrame() call

        std::vector<Frame> m_frames;    //List of animation frames

        unsigned m_framePointer = 0;    //The index of the current active frame
        const unsigned FRAME_WIDTH;
        const unsigned FRAME_HEIGHT;

};

#endif /* Animation_hpp */
