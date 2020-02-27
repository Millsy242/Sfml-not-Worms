//
//  ResourceHolder.cpp
//  GameEngineSFML
//
//  Created by Daniel Harvey on 18/02/2020.
//  Copyright © 2020 Daniel Harvey. All rights reserved.
//

#include "ResourceHolder.hpp"


ResourceHolder& ResourceHolder::get()
{
    static ResourceHolder holder;
    return holder;
}

ResourceHolder::ResourceHolder() : fonts("Fonts/", "ttf"), textures("Textures/", "png"), soundBuffers("Sounds/", "ogg")
{

}
