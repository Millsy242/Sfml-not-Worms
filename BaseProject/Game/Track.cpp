//
//  Track.cpp
//  BaseProject
//
//  Created by Daniel Harvey on 15/09/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#include "Track.hpp"
#include "Yaml.hpp"

void Track::Start()
{
    return;
}
void Track::LoadTexture(std::string filepath)
{
    EntityTexture.loadFromFile(filepath);
    EntitySprite.setTexture(EntityTexture);
}
void Track::EntityUpdate()
{
    return;
}
void Track::Render(Window *window)
{
    window->draw(EntitySprite);
    RSpline.DrawSelf(window);
    LSpline.DrawSelf(window);
    
    
}
void Track::Input(sf::Event event)
{
    return;
}
void Track::Exit()
{
    return;
}
bool Track::LoadTrackFromFile(std::string filepath)
{
    Yaml::Node root;
    try
    {
        Yaml::Parse(root, filepath.data());
    }
    catch(const Yaml::Exception e)
    {
        std::cout << "Exception " << e.Type() << ": " << e.what() << std::endl;
        return false; 
    }
    
    numnodes    = root["NumNodes"].As<int>();
    Sector1     = root["Sector1"].As<int>();
    Sector2     = root["Sector2"].As<int>();
    Sector3     = root["Sector3"].As<int>();
    StartNode   = root["StartLine"].As<int>();
    EndNode     = root["FinishLine"].As<int>();
    TrackWidth  = root["TrackWidth"].As<float>();
    
    float Tx,Ty;
    std::string name;
    for(int i{0};i<numnodes;i++)
    {
        name = "Node" + std::to_string(i);
        Tx = root[name + "_X"].As<int>();
        Ty = root[name + "_Y"].As<int>();
        CSpline.AddPoint(sf::Vector2f(Tx,Ty));
        LSpline.AddPoint(sf::Vector2f(Tx,Ty));
        RSpline.AddPoint(sf::Vector2f(Tx,Ty));
    }
    for(int i{0}; i<numnodes;i++)
    {
        auto p1 = CSpline.GetSplinePoint(i);
        auto g1 = CSpline.GetSplineGradient(i);
        float glen = sqrt(g1.x*g1.x+g1.y*g1.y);
        
        LSpline.points[i].x = p1.x + TrackWidth * (-g1.y / glen);
        LSpline.points[i].y = p1.y + TrackWidth * ( g1.x / glen);
        RSpline.points[i].x = p1.x - TrackWidth * (-g1.y / glen);
        RSpline.points[i].y = p1.y - TrackWidth * (g1.x / glen);
        
        LSpline.UpdateSplineProperties();
        RSpline.UpdateSplineProperties();
        
       // float r = atan2(-g1.y, g1.x);
        //nodes[i].Line.setPoints({TrackWidth * sin(r) + p1.x, trackwidth * cos(r) + p1.y}, {-trackwidth * sin(r) + p1.x, -trackwidth * cos(r) + p1.y});
    }
    CSpline.UpdateSplineProperties();
    
    LoadTexture(root["ImagePath"].As<std::string>());
    
    
    
    return true;
}
sf::Color Track::getPixel(sf::Vector2f point)
{
    return sf::Color::Black;
}
