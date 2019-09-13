//
//  main.cpp
//  BaseProject
//
//  Created by Daniel Harvey on 15/06/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Game.hpp"
#include "Menu.hpp"
#include "imgui.h"
#include "imgui-SFML.h"
#include <thread>


int main()
{
    Menu m;
    m.Start();
    m.Update();
    
    Game g;
    g.Start();
    g.Update();

    return 0;
}
