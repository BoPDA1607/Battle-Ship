#include "D:\PBL2\header\Map.h"

int Map::mapSize = 6;

Map::Map()
    : isFull(mapSize*mapSize)
{ }
Map::Map(const int x0, const int y0, const int size)
{
    this->m = new Node*[Map::mapSize];
    for(int i = 0; i < Map::mapSize; i++)
    {
        *(this->m + i) = new Node[Map::mapSize];
        for(int j = 0; j < Map::mapSize; j++)
        {
            *(*(this->m + i) + j) = Node(j + 1, i + 1, (j+x0)*size, (i+y0)*size, size, size, 0.0f);
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
void Map::checkMap(SDL_Renderer& rend, const int size, bool& isStart)
{
    if(!isStart) return;
    Graphics gMissNode;
    Graphics gHitNode;
    if(size == 80)
    {
        gMissNode("images/Miss.bmp", rend);
        gHitNode("images/hitNode.bmp", rend);
    }
    else
    {
        gMissNode("images/Miss1.bmp", rend);
        gHitNode("images/hitNode1.bmp", rend);
    }
    
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
bool Map::PlaceInMap()
{
    for(int i = 0; i < Map::mapSize; i++)
    {
        for(int j = 0; j < Map::mapSize; j++)
        {
            if((*(this->m + i) + j)->GetPlace() > 1)
                return false;
        }
    }

    return true;
}
Map& Map::operator()(const int x0, const int y0, const int size)
{
    for(int i = 0; i < Map::mapSize; i++)
    {
        for(int j = 0; j < Map::mapSize; j++)
        {
            *(*(this->m + i) + j) = Node(j, i, (j+x0)*size, (i+y0)*size, size, size, 0.0f);
        }
    }

    return (*this);
}
void Map::SetDefault(const int value)
{
    for(int i = 0; i < Map::mapSize; i++)
    {
        for(int j = 0; j < Map::mapSize; j++)
        {
            (*(this->m + i) + j)->GetPlace() = value;
        }
    }
}
Node* Map::FindNear(Node& n, int angle)
{
    switch (angle)
    {
        case 0: return this->getNode(n.GetX() + 1, n.GetY());
        case 90: return this->getNode(n.GetX(), n.GetY() - 1);
        case 180: return this->getNode(n.GetX() - 1, n.GetY());
        case 270: return this->getNode(n.GetX(), n.GetY() + 1);
    }
    return NULL;
}