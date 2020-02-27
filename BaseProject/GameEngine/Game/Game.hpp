//
//  Game.hpp
//  BaseProject
//
//  Created by Daniel Harvey on 13/09/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp
#include "WindowHolder.hpp"
#include "SelbaWard.hpp"

#include "imgui_memory_editor.h"
class Game : public WindowHolder
{
public:
    Game(std::shared_ptr<ige::FileLogger> LOG,std::shared_ptr<SettingsManager> SM);
    ~Game();
    
    virtual void Start() override;
    virtual void Input(std::queue<sf::Event> &events, float dt) override;
    virtual void Render(std::shared_ptr<Window> window) override;
    virtual void UI() override;
    virtual void EarlyUpdate() override;
    virtual void LateUpdate() override;
    virtual void FixedUpdate(float dt) override;
    virtual void DebugRender(std::shared_ptr<Window> window);
    virtual void addObject(Base *b);
    void Stats() override; 
    Base* getObject(unsigned int pos);
protected:
    void GameUI();
    void SetGameArea(myRect R);
    MemoryEditor mem_edit;    
    myRect GameArea{0,0,0,0};
    sf::RectangleShape GameAreaShape;
    
    bool DebugMemoryEditer = false;
    int selected = 0; 
    std::vector<Base*> ObjectVector;
    
};
#endif /* Game_hpp */

