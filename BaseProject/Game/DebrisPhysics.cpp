//
//  DebrisPhysics.cpp
//  WORMS
//
//  Created by Daniel Harvey on 27/02/2020.
//  Copyright © 2020 Daniel Harvey. All rights reserved.
//

#include "DebrisPhysics.hpp"

std::vector<std::pair<float, float>> DefineDebris()
{
    // A small unit rectangle
    std::vector<std::pair<float, float>> vecModel;
    vecModel.push_back({ 0.0f, 0.0f });
    vecModel.push_back({ 1.0f, 0.0f });
    vecModel.push_back({ 1.0f, 1.0f });
    vecModel.push_back({ 0.0f, 1.0f });
    
    for (auto &v : vecModel)
    {
        v.first /= 0.35f; v.second /= 0.35f;
    }
    
    return vecModel;
}
std::vector<std::pair<float, float>> Debris::vecModel = DefineDebris();
