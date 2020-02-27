//
//  Inputs.cpp
//  GameEngineSFML
//
//  Created by Daniel Harvey on 25/01/2020.
//  Copyright © 2020 Daniel Harvey. All rights reserved.
//

#include "Inputs.hpp"
bool eventManager::Testevent(std::string EventName, sf::Event &event)
{
    if(inputconfigs.find(EventName) == inputconfigs.end())
    {
        return false;
    }
    
    if(inputconfigs[EventName].myInputType == eMouseInput)
    {
        if(inputconfigs[EventName].myEventType == event.type &&
           inputconfigs[EventName].myMouseButton == event.mouseButton.button)
        {
            return true;
        }
    }
    if(inputconfigs[EventName].myInputType == eKeyboardInput)
    {
        if(inputconfigs[EventName].myEventType == event.type &&
           inputconfigs[EventName].myKeyCode == event.key.code)
        {
            return true;
        }
    }
    
    return false;
}
bool eventManager::Addevent(std::string EventName, Input i)
{
    if(inputconfigs.find(EventName) != inputconfigs.end())
    {
        inputconfigs[EventName] = i;
        return true; 
    }
    return false;
}
