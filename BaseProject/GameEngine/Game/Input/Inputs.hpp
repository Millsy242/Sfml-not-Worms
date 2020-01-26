//
//  Inputs.hpp
//  GameEngineSFML
//
//  Created by Daniel Harvey on 25/01/2020.
//  Copyright © 2020 Daniel Harvey. All rights reserved.
//

#ifndef Inputs_hpp
#define Inputs_hpp

#include <SFML/Graphics.hpp>
#include <unordered_map>

enum  InputType
{
    eKeyboardInput,
    eMouseInput,
    eJoystickInput
};

struct Input
{
    InputType myInputType;
    sf::Event::EventType myEventType;
    sf::Keyboard::Key myKeyCode;
    sf::Mouse::Button myMouseButton;
};

class eventManager
{
public:
    eventManager();
    ~eventManager(){};
    
    bool Testevent(std::string EventName, sf::Event &event);
    bool Addevent(std::string EventName, Input i);
    
private:
    std::unordered_map<std::string, Input> inputconfigs;
};

#endif /* Inputs_hpp */
