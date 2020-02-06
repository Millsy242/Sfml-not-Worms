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
#include "Rect.hpp"

class Game : public WindowHolder
{
public:
    Game(std::shared_ptr<ige::FileLogger> LOG,std::shared_ptr<SettingsManager> SM);
    ~Game(){};
    
    virtual void Start() override;
    virtual void Input(std::queue<sf::Event> &events, float dt) override;
    virtual void Render(std::shared_ptr<Window> window) override;
    virtual void UI() override;
    virtual void EarlyUpdate() override;
    virtual void LateUpdate() override;
    virtual void FixedUpdate(float dt) override;
protected:
    void GameUI();
    void SetGameArea(myRect R);

    myRect GameArea{0,0,0,0};
    sf::RectangleShape GameAreaShape;
    sf::Texture DebugTexture,ExitTexture,PauseTexture,SettingsTexture;
};
#endif /* Game_hpp */

