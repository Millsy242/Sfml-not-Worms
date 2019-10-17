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

class Window
{
public:
    
    Window();
    
    void Start(const std::string& windowName);
    
    void Update();
    
    void BeginDraw(sf::Color colour = sf::Color::Magenta);
    void draw(const sf::Drawable& drawable);
    void EndDraw();
	
    bool IsOpen() const;
	sf::Vector2u GetCentre();
	void Process();
	
	void sharpen(std::vector<sf::Uint8> &pixels);
	
	void SetTitle(std::string &title);
	
	bool RenderToTexture = false;
    
    float getDT();
    
    int GetFPS();
    
    sf::Event GetEvent();
    
    sf::Vector2u GetSize();
    
private:
    void CalculateDT(); 
    
    sf::RenderWindow window;
	sf::RenderTexture rendertexture;
	sf::Sprite windowtexture;
	FPS fps;
    float deltatime;
    sf::Clock clock;
    sf::Event event;
    bool temp = false;
};


#endif /* Window_hpp */
