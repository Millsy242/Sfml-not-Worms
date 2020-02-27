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

void WindowHolder::Start()
{
	Active = true;
	
	c.restart();
}
void WindowHolder::GiveWindow(std::shared_ptr<Window> w)
{
	window = w;
}
void WindowHolder::Stats()
{
	*log << "Display Stats";
	ImGuiWindowFlags window_flags = 0;
	window_flags |= ImGuiWindowFlags_NoMove;
	window_flags |= ImGuiWindowFlags_NoResize;
	window_flags |= ImGuiWindowFlags_AlwaysAutoResize;
	window_flags |= ImGuiWindowFlags_NoBackground;
	window_flags |= ImGuiWindowFlags_NoNav;
	window_flags |= ImGuiWindowFlags_NoInputs;
	window_flags |= ImGuiWindowFlags_NoCollapse;
	window_flags |= ImGuiWindowFlags_NoNavFocus;
	window_flags |= ImGuiWindowFlags_NoTitleBar;
	
    ImGui::Begin("Stats",NULL,window_flags);
	ImGui::Text("FPS: %i \nDT: %fms",(int)window->GetFPS(),window->getDT()*1000);
    ImGui::End();
	
	if(Debug)
	{
		if(DebugMetrics)
			ImGui::ShowMetricsWindow();
		if(DebugUserGuide)
			ImGui::ShowUserGuide();
		if(DebugStyleSel)
			ImGui::ShowStyleSelector("Style");
		if(DebugStyleEditer)
			ImGui::ShowStyleEditor();
		

	}
}

void WindowHolder::Update()
{
    timestep.setStep(1/20.0);    
	Active = true;
	while (Active )
	{
		window->Update();
		Stats();
		UI();
		Input(window->events, window->getDT());
		timestep.update(window->getDT());
		if(!Pause)
		{
			//Ensure Fps doesnt change User experiance
			while (Active && timestep.isTimeToIntegrate())
			{
				EarlyUpdate();
				LateUpdate();
			}
			FixedUpdate(window->getDT());
		}
		Render(window);
	}
	return;
}
void WindowHolder::Exit()
{
	
}
