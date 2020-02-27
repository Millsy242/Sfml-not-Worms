//
//  ResourceHolder.hpp
//  GameEngineSFML
//
//  Created by Daniel Harvey on 18/02/2020.
//  Copyright © 2020 Daniel Harvey. All rights reserved.
//

#ifndef ResourceHolder_hpp
#define ResourceHolder_hpp

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ResourceManager.hpp"
#include "NonCopyable.h"
#include "NonMoveable.h"

class ResourceHolder : public NonCopyable, public NonMovable
{
    public:
        static ResourceHolder& get();

        ResourceManager<sf::Font>           fonts;
        ResourceManager<sf::Texture>        textures;
        ResourceManager<sf::SoundBuffer>    soundBuffers;

    private:
        ResourceHolder();
};

#endif /* ResourceHolder_hpp */
