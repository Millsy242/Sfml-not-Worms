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


Window::Window()
{  

}

void Window::Start(const std::string& windowName)
{
    window.create(sf::VideoMode(1920,1080), windowName, sf::Style::Default);
    window.setFramerateLimit(1000);
    rendertexture.create(window.getSize().x,window.getSize().y);
    ImGui::SFML::Init(window);
    CalculateDT();
}
void Window::Update()
{
	fps.update();
    ImGui::SFML::Update(window, sf::seconds(deltatime));
   
    if (window.pollEvent(event))
    {
		 ImGui::SFML::ProcessEvent(event);
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}
sf::Event Window::GetEvent()
{
    return event;
}

void Window::BeginDraw(sf::Color colour)
{
    window.clear(colour);
    if(RenderToTexture)
	rendertexture.clear(colour);
}

void Window::draw(const sf::Drawable& drawable)
{
	if(RenderToTexture)
		rendertexture.draw(drawable);
	else
    	window.draw(drawable);
}

void Window::EndDraw()
{
    ImGui::EndFrame();
	if(RenderToTexture)
		Process();
    
    rendertexture.display();

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
void Window::Process()
{
	windowtexture.setTexture(rendertexture.getTexture());
	
	windowtexture.setOrigin(windowtexture.getTextureRect().width/2, windowtexture.getTextureRect().height/2);
	
	windowtexture.setPosition(sf::Vector2f(GetCentre()));
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		//windowtexture.setColor(sf::Color(128,128,128));
		windowtexture.scale(1.01, 1.01);
	}

	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
	{
		//windowtexture.setColor(sf::Color::Blue);
		windowtexture.scale(0.99, 0.99);
	}

	sf::Texture texture = *windowtexture.getTexture();
	
	//texture.setRepeated(true);
	//texture.setSmooth(true);
	windowtexture.setTexture(texture);
	
	window.draw(windowtexture);
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


/*
 image = texture.copyToImage();
 std::vector<sf::Uint8> pixels;
 for(int y  = 0; y<600;y++)
 {
 for(int x  = 0; x<800;x++)
 {
 pixels.push_back(sf::Color(image.getPixel(x,y)).r);
 pixels.push_back(sf::Color(image.getPixel(x,y)).g);
 pixels.push_back(sf::Color(image.getPixel(x,y)).b);
 pixels.push_back(sf::Color(image.getPixel(x,y)).a);
 }
 }
 
 image.create(800, 600, pixels.data());
 texture.loadFromImage(image);
 */
