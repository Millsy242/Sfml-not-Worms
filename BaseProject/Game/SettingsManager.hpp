//
//  SettingsManager.hpp
//  BaseProject
//
//  Created by Daniel Harvey on 27/10/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#ifndef SettingsManager_hpp
#define SettingsManager_hpp

#include "SettingsParser.hpp"
#include <SFML/Graphics.hpp>

class SettingsManager
{
public:
    SettingsManager();
    ~SettingsManager();
    
    void Setup();
    void UpdateFile();
    
    sf::Vector2u MenuSize{400,600};
    sf::Vector2u GameSize{1920,1080};
    
private:
    SettingsParser parse;
    std::string FileName = "Settings.txt";

};

#endif /* SettingsManager_hpp */
