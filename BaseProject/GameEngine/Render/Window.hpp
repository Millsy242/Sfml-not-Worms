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
#include "FpsLite.hpp"
#include <SFML/Graphics.hpp>
#include "FileLogger.hpp"
#include <thread>
#include <queue>
#include "Rect.hpp"
#include <TGUI/TGUI.hpp>
 

class Window
{
public:
    Window(std::shared_ptr<ige::FileLogger> LOG);
    void Start(const std::string& windowName,sf::Vector2u WindowSize,bool Fullscreen = false);
    void Update();
    void BeginDraw(sf::Color colour = sf::Color::Magenta);
    void draw(const sf::Drawable& drawable);
    void draw(myRect &rec,sf::Color col = sf::Color::Red);
    void draw(const sf::Vertex *vertices, std::size_t vertexCount, sf::PrimitiveType type);
    void draw(const sf::VertexBuffer &vertexBuffer);
    void draw(const sf::VertexBuffer &vertexBuffer, std::size_t firstVertex, std::size_t vertexCount);
    void DrawWireFrameModel(const std::vector<std::pair<float, float>> &vecModelCoordinates, float x, float y, float r = 0.0f, float s = 1.0f, sf::Color col = sf::Color::White);
    void EndDraw();
    void Close();
    void SetSize(sf::Vector2u size);
    void SetVsync(bool Vsync);
    void SetTitle(std::string &title);
    bool IsOpen() const;
    void OnResize(float newx, float newy);
    sf::View GetView(); 
    float getDT();
    double GetFPS();
    
    sf::Event GetEvent();
    sf::Vector2u GetSize();
    sf::Vector2u GetCentre();
    sf::Vector2i GetMouse();
    
    sf::RenderWindow window;
    
    bool RenderToTexture = false;
    
    std::queue<sf::Event> events;
    
    
    
private:
    void CalculateDT();

    sf::RenderTexture rendertexture;
    sf::Sprite windowtexture;
    sf::Clock clock;
    sf::Event event;
    
    tgui::Gui GUI; 
    
    kairos::FpsLite fps;
    float deltatime;

    std::shared_ptr<ige::FileLogger> log;
};


#endif /* Window_hpp */

