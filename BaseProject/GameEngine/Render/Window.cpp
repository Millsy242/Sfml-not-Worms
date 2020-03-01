//
//  Window.cpp
//  SFGameEngine
//
//  Created by Daniel Harvey on 27/05/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#include "Window.hpp"
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>


Window::Window(std::shared_ptr<ige::FileLogger> LOG)
{
    log = LOG;
}

void Window::Start(const std::string& windowName,sf::Vector2u WindowSize, bool Fullscreen)
{
    *log << "Creating SFML window";
    
    if(Fullscreen)
        window.create(sf::VideoMode(WindowSize.x,WindowSize.y,32), windowName, sf::Style::Fullscreen);
    else
        window.create(sf::VideoMode(WindowSize.x,WindowSize.y,32), windowName, sf::Style::Default);
    
    window.setFramerateLimit(1000);
    
    *log << "Setting up ImGui";
    ImGui::SFML::Init(window);
        *log << "Setting up TGui";
    GUI.setTarget(window);
    CalculateDT();
    
}
sf::Vector2i Window::GetMouse()
{
    return sf::Mouse::getPosition(window);
}
void Window::Close()
{
    window.close();
}
void Window::SetVsync(bool Vsync)
{
    window.setVerticalSyncEnabled(Vsync);
}
void Window::SetSize(sf::Vector2u size)
{
    window.setSize(size);
}
void Window::Update()
{
    *log << "Updating Window";
    fps.update();
    ImGui::SFML::Update(window, sf::seconds(deltatime));
   
    while (window.pollEvent(event))
    {
         ImGui::SFML::ProcessEvent(event);
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        else if (event.type == sf::Event::Resized)
        {
            OnResize(event.size.width, event.size.height);
        }
        else
        {
            events.push(event);
        }
    }
}
sf::Event Window::GetEvent()
{
    return event;
}
void Window::OnResize(float newx, float newy)
{
    SetSize(sf::Vector2u(newx,newy));
}

void Window::BeginDraw(sf::Color colour)
{
    *log << "Starting render";
    window.clear(colour);
    if(RenderToTexture)
    rendertexture.clear(colour);
}

void Window::draw(const sf::Drawable& drawable)
{
     *log << "Drawing drawable";
      window.draw(drawable);
}
void Window::draw(const sf::Vertex *vertices, std::size_t vertexCount, sf::PrimitiveType type)
{
    window.draw(vertices,vertexCount,type);
}
void Window::draw(const sf::VertexBuffer &vertexBuffer)
{
    window.draw(vertexBuffer);
}
void Window::draw(const sf::VertexBuffer &vertexBuffer, std::size_t firstVertex, std::size_t vertexCount)
{
    window.draw(vertexBuffer,firstVertex,vertexCount);
}
void Window::draw(myRect &rec,sf::Color col)
{
    sf::VertexArray arr(sf::Lines,8);
    
    arr[0].position = sf::Vector2f(rec.left,rec.top);
    arr[0].color = col;
    arr[1].position = sf::Vector2f(rec.right,rec.top);
    arr[1].color = col;
    arr[2].position = sf::Vector2f(rec.right,rec.top);
    arr[2].color = col;
    arr[3].position = sf::Vector2f(rec.right,rec.base);
    arr[3].color = col;
    arr[4].position = sf::Vector2f(rec.left,rec.top);
    arr[4].color = col;
    arr[5].position = sf::Vector2f(rec.left,rec.base);
    arr[5].color = col;
    arr[6].position = sf::Vector2f(rec.left,rec.base);
    arr[6].color = col;
    arr[7].position = sf::Vector2f(rec.right,rec.base);
    arr[7].color = col;

    window.draw(arr);
}
void Window::EndDraw()
{
     *log << "Finishing Draw";

    ImGui::EndFrame();
    //rendertexture.display();
    ImGui::SFML::Render(window);
    window.display();
    CalculateDT();
}
void Window::CalculateDT()
{
    deltatime = clock.restart().asSeconds();
}

bool Window::IsOpen() const
{
    return window.isOpen();
}
sf::Vector2u Window::GetSize()
{
    return window.getSize();
}
sf::Vector2u Window::GetCentre()
{
    unsigned int x = window.getSize().x/2;
    unsigned int y = window.getSize().y/2;
    
    return sf::Vector2u(x,y);
}

void Window::SetTitle(std::string &title)
{
    window.setTitle(title);
}
float Window::getDT()
{
    return deltatime;
}
double Window::GetFPS()
{
    return fps.getFps();
}
void Window::DrawWireFrameModel(const std::vector<std::pair<float, float>> &vecModelCoordinates, float x, float y, float r, float s, sf::Color col)
{
    //Please note: this code was taken and adapted from the console game engine, writted by Javidx9
    //https://github.com/OneLoneCoder/videos/blob/master/olcConsoleGameEngineGL.h
    // pair.first = x coordinate
    // pair.second = y coordinate

    // Create translated model vector of coordinate pairs
    std::vector<std::pair<float, float>> vecTransformedCoordinates;
    int verts = (int)vecModelCoordinates.size();
    vecTransformedCoordinates.resize(verts);

    // Rotate
    for (int i = 0; i < verts; i++)
    {
        vecTransformedCoordinates[i].first = vecModelCoordinates[i].first * cosf(r) - vecModelCoordinates[i].second * sinf(r);
        vecTransformedCoordinates[i].second = vecModelCoordinates[i].first * sinf(r) + vecModelCoordinates[i].second * cosf(r);
    }

    // Scale
    for (int i = 0; i < verts; i++)
    {
        vecTransformedCoordinates[i].first = vecTransformedCoordinates[i].first * s;
        vecTransformedCoordinates[i].second = vecTransformedCoordinates[i].second * s;
    }

    // Translate
    for (int i = 0; i < verts; i++)
    {
        vecTransformedCoordinates[i].first = vecTransformedCoordinates[i].first + x;
        vecTransformedCoordinates[i].second = vecTransformedCoordinates[i].second + y;
    }

    // Draw Closed Polygon
    for (int i = 0; i < verts + 1; i++)
    {
        int j = (i + 1);
        
        sf::Vertex line[] =
        {
            sf::Vertex({vecTransformedCoordinates[i % verts].first, vecTransformedCoordinates[i % verts].second}),
            sf::Vertex({vecTransformedCoordinates[j % verts].first, vecTransformedCoordinates[j % verts].second})
        };
        line[0].color = col;
        line[1].color = col;
        draw(line, 2, sf::Lines);
    }
}
sf::View Window::GetView()
{
    return window.getView();
}
