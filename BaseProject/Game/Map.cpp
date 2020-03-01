
 //
 //  Map.cpp
 //  WORMS
 //
 //  Created by Daniel Harvey on 29/02/2020.
 //  Copyright © 2020 Daniel Harvey. All rights reserved.
 //

 #include "Map.hpp"

 Map::Map()
 {
     map =  new unsigned char[nMapWidth * nMapHeight];
     memset(map, 0, nMapWidth*nMapHeight * sizeof(unsigned char));
 }
 Map::Map(int Width,int Height)
 {
     nMapWidth = Width;
     nMapHeight = Height;
     map =  new unsigned char[nMapWidth * nMapHeight];
     memset(map, 0, nMapWidth*nMapHeight * sizeof(unsigned char));
 }
Map::~Map()
{

}
 int Map::getWidth()
 {
     return nMapWidth  ;
 }
 int Map::getHeight()
 {
     return nMapHeight  ;
 }

 void Map::CreateMap()
 {
     Mapbuffer.clear();
     sizeOfBuffer = nMapWidth * nMapHeight * 4;
     Mapbuffer.setPrimitiveType(sf::PrimitiveType::Quads);
     Mapbuffer.resize(sizeOfBuffer);

     // Used 1D Perlin Noise
     float *fSurface = new float[nMapWidth];
     float *fNoiseSeed = new float[nMapWidth];

     // Populate with noise
     for (int i = 0; i < nMapWidth; i++)
         fNoiseSeed[i] = (float)rand() / (float)RAND_MAX;

     // Clamp noise to half way up screen
     fNoiseSeed[0] = 0.5f;

     // Generate 1D map
     PerlinNoise1D(nMapWidth, fNoiseSeed, 8, 2.0f, fSurface);
     
     for (int x = 0; x < nMapWidth; x++)
     {
         for (int y = 0; y < nMapHeight; y++)
         {
             if (y >= fSurface[x] * nMapHeight)
             {
                 map[y * nMapWidth + x] = 1;
             }
             else
             {
                 map[y * nMapWidth + x] = 0;
             }
             
             
              
         }
     }

     // Clean up!
     delete[] fSurface;
     delete[] fNoiseSeed;
 }
 void Map::Render(std::shared_ptr<Window> window, int CamX, int CamY)
 {

     for (int y = 0; y <= window->GetSize().y; y++)
     {
         for (int x = 0; x <= window->GetSize().x; x++)
         {
             sf::Vertex* quad = &Mapbuffer[((y + CamY)*nMapWidth + (x + CamX)) *4];
             
             //bottom left
             quad[0].position = sf::Vector2f(x * tilesize, y * tilesize);
             //top left
             quad[1].position = sf::Vector2f((x + 1) * tilesize, y * tilesize);
             //top right
             quad[2].position = sf::Vector2f((x + 1) * tilesize, (y + 1) * tilesize);
             //top left
             quad[3].position = sf::Vector2f(x * tilesize, (y + 1) * tilesize);
     
             switch(getFromMap(x+ CamX, y + CamY))
             {
                 case 0:
                     //Draw Sky
                     quad[0].color = sf::Color(135,206,235);
                     quad[1].color = sf::Color(135,206,235);
                     quad[2].color = sf::Color(135,206,235);
                     quad[3].color = sf::Color(135,206,235);
                     break;
                 case 1:
                     //draw land
                     quad[0].color = sf::Color(76,187,23);
                     quad[1].color = sf::Color(76,187,23);
                     quad[2].color = sf::Color(76,187,23);
                     quad[3].color = sf::Color(76,187,23);
                     break;
                 default:
                     quad[0].color = sf::Color::Magenta;
                     quad[1].color = sf::Color::Magenta;
                     quad[2].color = sf::Color::Magenta;
                     quad[3].color = sf::Color::Magenta;
                     break;
             }
              
         }
     }
     
     window->draw(Mapbuffer);
    // Mapbuffer.clear();
    // Mapbuffer.resize(sizeOfBuffer);
 }


 void Map::PerlinNoise1D(int nCount, float *fSeed, int nOctaves, float fBias, float *fOutput)
 {
     // Used 1D Perlin Noise
     for (int x = 0; x < nCount; x++)
     {
         float fNoise = 0.0f;
         float fScaleAcc = 0.0f;
         float fScale = 1.0f;

         for (int o = 0; o < nOctaves; o++)
         {
             int nPitch = nCount >> o;
             int nSample1 = (x / nPitch) * nPitch;
             int nSample2 = (nSample1 + nPitch) % nCount;
             float fBlend = (float)(x - nSample1) / (float)nPitch;
             float fSample = (1.0f - fBlend) * fSeed[nSample1] + fBlend * fSeed[nSample2];
             fScaleAcc += fScale;
             fNoise += fSample * fScale;
             fScale = fScale / fBias;
         }

         // Scale to seed range
         fOutput[x] = fNoise / fScaleAcc;
     }
 }
 unsigned char Map::getFromMap(int x, int y)
 {
     return map[(y*nMapWidth) + x] ;
 }
 void Map::SetInMap(int x, int y, unsigned char value)
 {
     map[(y*nMapWidth)+x] = value;
 }
