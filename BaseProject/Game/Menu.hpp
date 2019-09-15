//
//  Menu.hpp
//  BaseProject
//
//  Created by Daniel Harvey on 13/09/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include "WindowHolder.hpp"
#include <stdio.h>

class Menu : public WindowHolder
{
    public:
    Menu();
    ~Menu(){};
        
        void Start() override;
        void Input(sf::Event e) override;
        void Render(Window *window) override;
        void UI() override;
        void EarlyUpdate() override;
        void LateUpdate() override;

    
    private:
};
#endif /* Menu_hpp */
