//
//  Base.cpp
//  GameEngineSFML
//
//  Created by Daniel Harvey on 19/02/2020.
//  Copyright © 2020 Daniel Harvey. All rights reserved.
//

#include "Base.hpp"

void Base::Start()
{
    Bounds = myRect(Size.x,Size.y);
    Bounds.move(Position.x,Position.y);
};
void Base::Render(std::shared_ptr<Window> window)
{
    
    if(drawRect)
    {
        if(Selected)
            window->draw(Bounds,sf::Color::Magenta);
        else
            window->draw(Bounds);
    }
};
void Base::DebugUI(int i)
{
    ImGui::Begin("DebugUI");
    if (ImGui::CollapsingHeader(std::to_string(i).c_str()))
    {
        ImGui::Text("%s:\nPosition: %f,%f\nSize: %f,%f",(ClassName+std::to_string(i)).c_str(),Position.x,Position.y,Size.x,Size.y);
       
        ImGui::Checkbox(std::string("Show Bounding Rect ##" + std::to_string(i)).c_str(), &drawRect);
        ImGui::Checkbox(std::string("Selected ##" + std::to_string(i)).c_str(), &Selected);
    }
    ImGui::End();
      
};
void Base::DebugSelected(bool sel)
{
    Selected = sel;
    drawRect = true;
}
void Base::Update()
{
    
}
void Base::FixedUpdate(float dt)
{
    
}
void Base::Exit()
{
    
}
void Base::Input(std::queue<sf::Event> &events, float dt)
{
    
}
void Base::UI()
{
    
}
