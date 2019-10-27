//
//  SettingsManager.cpp
//  BaseProject
//
//  Created by Daniel Harvey on 27/10/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#include "SettingsManager.hpp"

SettingsManager::SettingsManager()
{
    
}
SettingsManager::~SettingsManager()
{
    UpdateFile();
}

void SettingsManager::Setup()
{
    if(parse.loadFromFile(FileName))
    {
        //load from file to data
        parse.get("MenuScreenWidth", MenuSize.x);
        parse.get("MenuScreenHeight", MenuSize.y);
        parse.get("GameScreenWidth", GameSize.x);
        parse.get("GameScreenHeight", GameSize.y);
    }
    else
    {
        UpdateFile();
    }
}
void SettingsManager::UpdateFile()
{
    parse.set("MenuScreenWidth", MenuSize.x);
    parse.set("MenuScreenHeight", MenuSize.y);
    parse.set("GameScreenWidth", GameSize.x);
    parse.set("GameScreenHeight", GameSize.y);
    parse.saveToFile(FileName);
}
