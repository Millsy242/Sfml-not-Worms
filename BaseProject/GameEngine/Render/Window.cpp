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
    //rendertexture.create(window.getSize().x,window.getSize().y);
    *log << "Setting up ImGui";
    ImGui::SFML::Init(window);
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
    if(RenderToTexture)
        rendertexture.draw(drawable);
    else
        window.draw(drawable);
}
void Window::draw(myRect &rec)
{
    sf::Vertex top[4],right[2],left[2],base[2];
    
    top[0].position = sf::Vector2f(rec.left,rec.top);
    top[0].color = sf::Color::Red;
    top[1].position = sf::Vector2f(rec.right,rec.top);
    top[1].color = sf::Color::Red;
    right[0].position = sf::Vector2f(rec.right,rec.top);
    right[0].color = sf::Color::Red;
    right[1].position = sf::Vector2f(rec.right,rec.base);
    right[1].color = sf::Color::Red;
    left[0].position = sf::Vector2f(rec.left,rec.top);
    left[0].color = sf::Color::Red;
    left[1].position = sf::Vector2f(rec.left,rec.base);
    left[1].color = sf::Color::Red;
    base[0].position = sf::Vector2f(rec.left,rec.base);
    base[0].color = sf::Color::Red;
    base[1].position = sf::Vector2f(rec.right,rec.base);
    base[1].color = sf::Color::Red;
    

    
    window.draw(top,2,sf::Lines);
    window.draw(right,2,sf::Lines);
    window.draw(left,2,sf::Lines);
    window.draw(base,2,sf::Lines);
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
int Window::GetFPS()
{
    return fps.getFPS();
}
