//
//  MissilePhysics.cpp
//  WORMS
//
//  Created by Daniel Harvey on 27/02/2020.
//  Copyright © 2020 Daniel Harvey. All rights reserved.
//

#include "MissilePhysics.hpp"

std::vector<std::pair<float, float>> DefineMissile()
{
    // Defines a rocket like shape
    std::vector<std::pair<float, float>> vecModel;
    vecModel.push_back({ 0.0f, 0.0f });
    vecModel.push_back({ 1.0f, 1.0f });
    vecModel.push_back({ 2.0f, 1.0f });
    vecModel.push_back({ 2.5f, 0.0f });
    vecModel.push_back({ 2.0f, -1.0f });
    vecModel.push_back({ 1.0f, -1.0f });
    vecModel.push_back({ 0.0f, 0.0f });
    vecModel.push_back({ -1.0f, -1.0f });
    vecModel.push_back({ -2.5f, -1.0f });
    vecModel.push_back({ -2.0f, 0.0f });
    vecModel.push_back({ -2.5f, 1.0f });
    vecModel.push_back({ -1.0f, 1.0f });
    
    // Scale points to make shape unit sized
    for (auto &v : vecModel)
    {
        v.first /= 0.35f; v.second /= 0.35f;
    }
    return vecModel;
}
std::vector<std::pair<float, float>> Missile::vecModel = DefineMissile();
