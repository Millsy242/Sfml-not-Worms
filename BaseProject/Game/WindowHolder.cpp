//
//  Game.cpp
//  BaseProject
//
//  Created by Daniel Harvey on 15/06/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#include "WindowHolder.hpp"
#include <math.h>
#include <iostream>

WindowHolder::WindowHolder() : window("Window")
{
	c.restart();
}

void WindowHolder::Start()
{

}

void WindowHolder::Stats()
{
	ImGuiWindowFlags window_flags = 0;
	window_flags |= ImGuiWindowFlags_NoMove;
	window_flags |= ImGuiWindowFlags_NoResize;
	window_flags |= ImGuiWindowFlags_NoBackground;
	window_flags |= ImGuiWindowFlags_NoNav;
	window_flags |= ImGuiWindowFlags_NoInputs;
	window_flags |= ImGuiWindowFlags_NoCollapse;
	window_flags |= ImGuiWindowFlags_NoNavFocus;
	window_flags |= ImGuiWindowFlags_NoTitleBar;
	
    ImGui::Begin("Stats",NULL,window_flags);
	ImGui::SetWindowSize("Stats", ImVec2(110,70));
    ImGui::Text("FPS: %i \nDT: %fms",window.GetFPS(),window.getDT()*1000);
    ImGui::End();
}

void WindowHolder::Update()
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
		Stats();
		UI();
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
void WindowHolder::Exit()
{
	
}
