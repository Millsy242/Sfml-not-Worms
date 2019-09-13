//
//  Game.cpp
//  BaseProject
//
//  Created by Daniel Harvey on 15/06/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#include "Game.hpp"
#include <math.h>
#include <iostream>

Game::Game() : window("Window")
{
	c.restart();
}

void Game::Start()
{

}

void Game::Update()
{
	const float frameDuration = 17;
	const int maxTimePerFrame = 200;
	float accumulatedTime = 0;
	
	while (window.IsOpen())
	{
		accumulatedTime += c.restart().asMilliseconds();
		if (accumulatedTime > maxTimePerFrame)
		{
			accumulatedTime = maxTimePerFrame;
		}
			window.Update();
		//Ensure Fps doesnt change User experiance
		while (accumulatedTime >= frameDuration)
		{
			accumulatedTime -= frameDuration;
			
			EarlyUpdate();
			LateUpdate();
		}
		
		Render();
		
	}
}
void Game::Input()
{
	
}
void Game::EarlyUpdate()
{


	
}
void Game::LateUpdate()
{

}
void Game::Render()
{
	window.BeginDraw(sf::Color::Green);
	

	
	window.EndDraw();
}


