//
//  Window.hpp
//  SFGameEngine
//
//  Created by Daniel Harvey on 27/05/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp


#include "imgui.h"
#include "imgui-SFML.h"
#include "FPS.hpp"
#include <SFML/Graphics.hpp>
#include "FileLogger.hpp"
#include <thread>

class Window
{
public:
    
    Window(ige::FileLogger *LOG);
    void Start(const std::string& windowName,sf::Vector2u WindowSize,bool Fullscreen = false);
    void Update();
    void BeginDraw(sf::Color colour = sf::Color::Magenta);
    void draw(const sf::Drawable& drawable);
    void EndDraw();
	
    void SetSize(sf::Vector2u size); 
    bool IsOpen() const;
	sf::Vector2u GetCentre();
	void SetTitle(std::string &title);
	bool RenderToTexture = false;
    float getDT();
    int GetFPS();
    sf::Event GetEvent();
    sf::Vector2u GetSize();
    void SetVsync(bool Vsync);
    
private:
    void CalculateDT();
    
    std::thread thread; 
    
    sf::RenderWindow window;
	sf::RenderTexture rendertexture;
	sf::Sprite windowtexture;
	FPS fps;
    float deltatime;
    sf::Clock clock;
    sf::Event event;
    ige::FileLogger *log; 
};


#endif /* Window_hpp */

