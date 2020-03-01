//
//  DummyPhysics.cpp
//  WORMS
//
//  Created by Daniel Harvey on 27/02/2020.
//  Copyright © 2020 Daniel Harvey. All rights reserved.
//

#include "DummyPhysics.hpp"

std::vector<std::pair<float, float>> DefineDummy()
{
    // Defines a circle with a line fom center to edge
    std::vector<std::pair<float, float>> vecModel;
    vecModel.push_back({ 0.0f, 0.0f });
    for (int i = 0; i < 10; i++)
        vecModel.push_back({ cosf(i / 9.0f * 2.0f * 3.14159f) *6, sinf(i / 9.0f * 2.0f * 3.14159f)*6 });
    return vecModel;
};
std::vector<std::pair<float, float>> Dummy::vecModel = DefineDummy();
