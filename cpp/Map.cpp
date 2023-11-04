#include "D:\PBL2\header\Map.h"

int Map::mapSize = 6;

Map::Map()
{ }
Map::Map(const int size)
{
    this->m = new Node*[Map::mapSize];
    for(int i = 0; i < Map::mapSize; i++)
    {
        *(this->m + i) = new Node[Map::mapSize];
        for(int j = 0; j < Map::mapSize; j++)
        {
            *(*(this->m + i) + j) = Node(0, 0, (j+1)*size, (i+1)*size, size, size, 0.0f);
        }
    }
}
Map::~Map()
{ 
    for(int i = 0; i < Map::mapSize; i++)
    {
        delete[] *(this->m + i);
    }
    delete[] this->m;
}
Node* Map::getNode(const int i, const int j)
{
    return (*(this->m + (j-1)) + (i-1));
}
void Map::checkMap(SDL_Renderer& rend)
{
    Graphics gMissNode("Miss.bmp", rend);
    Graphics gHitNode("hitNode.bmp", rend);
    for(int i = 0; i < Map::mapSize; i++)
    {
        for(int j = 0; j < Map::mapSize; j++)
        {
            if((*(this->m + i) + j)->GetHit() == 1)
            {
                gHitNode.Render(rend, (*(this->m + i) + j)->getRect(), 0.0f);
            }
            else if((*(this->m + i) + j)->GetHit() == 0)
            {
                gMissNode.Render(rend, (*(this->m + i) + j)->getRect(), 0.0f);
            }
        }
    }
}
bool Map::InRange(const int x, const int y)
{
    return (x >= (*(this->m + 0) + 0)->getRect()->x && y >= (*(this->m + 0) + 0)->getRect()->y
         && x <= (*(this->m + 5) + 5)->getRect()->x + 80 && y <= (*(this->m + 5) + 5)->getRect()->y + 80);
}
