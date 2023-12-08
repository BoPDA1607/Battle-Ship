#include "D:\PBL2.1\header\Map.h"

int Map::mapSize[3] = {6, 8, 10};

Map::Map()
    : isFull(mapSize[0]*mapSize[0])
{ }
Map::Map(const int x0, const int y0, const int ind)
{
    this->currentSize = Map::mapSize[ind];
    int size = Node::nodeSize[ind]; cout << size;
    this->m = new Node*[this->currentSize];
    for(int i = 0; i < this->currentSize; i++)
    {
        *(this->m + i) = new Node[this->currentSize];
        for(int j = 0; j < this->currentSize; j++)
        {
            *(*(this->m + i) + j) = Node(j + x0, i + y0, (j+x0)*size, (i+y0)*size, size, size, 0.0f);
        }
    }
}
Map::~Map()
{ 
    for(int i = 0; i < this->currentSize; i++)
    {
        delete[] *(this->m + i);
    }
    delete[] this->m;
}
Node* Map::getNode(int i, int j, const int x0, const int y0, const int ind)
{
    cout << "get node" << endl;
    return (*(this->m + (j-x0)) + (i-y0));
}
void Map::checkMap(SDL_Renderer& rend, const int ind, bool& isStart)
{
    if(!isStart) return;
    int size = Node::nodeSize[ind];
    Graphics gMissNode;
    Graphics gHitNode;
    
    if(size == 80)
    {
        gMissNode("images/Miss.bmp", rend);
        gHitNode("images/hitNode.bmp", rend);
    }
    else if(size == 60)
    {
        gMissNode("images/Miss.bmp", rend);
        gHitNode("images/hitNode.bmp", rend);
    }
    else
    {
        gMissNode("images/Miss.bmp", rend);
        gHitNode("images/hitNode.bmp", rend);
    }
    for(int i = 0; i < this->currentSize; i++)
    {
        for(int j = 0; j < this->currentSize; j++)
        {
            if((*(this->m + i) + j)->GetHit() == 1)
            {   
                cout << "Hit" << endl;
                gHitNode.Render(rend, (*(this->m + i) + j)->getRect(), 0.0f);
            }
            else if((*(this->m + i) + j)->GetHit() == 0)
            {
                cout << "Miss" << endl;
                gMissNode.Render(rend, (*(this->m + i) + j)->getRect(), 0.0f);
            }
        }
    }
}
bool Map::InRange(const int x, const int y, const int size)
{
    cout << this->currentSize << endl;
    return (x >= (*(this->m + 0) + 0)->getRect()->x && y >= (*(this->m + 0) + 0)->getRect()->y
         && x <= (*(this->m + this->currentSize-1) + this->currentSize-1)->getRect()->x + size && y <= (*(this->m + this->currentSize-1) + this->currentSize-1)->getRect()->y + size);
}
bool Map::PlaceInMap()
{
    for(int i = 0; i < this->currentSize; i++)
    {
        for(int j = 0; j < this->currentSize;j++)
        {
            if((*(this->m + i) + j)->GetPlace() > 1)
                return false;
        }
    }

    return true;
}
Map& Map::operator()(const int x0, const int y0, const int ind)
{
    this->currentSize = Map::mapSize[ind];
    int size = Node::nodeSize[ind];
    for(int i = 0; i < this->currentSize; i++)
    {
        for(int j = 0; j < this->currentSize; j++)
        {
            *(*(this->m + i) + j) = Node(j + x0, i + y0, (j+x0)*size, (i+y0)*size, size, size, 0.0f);
        }
    }

    return (*this);
}
void Map::SetDefault(const int value)
{
    for(int i = 0; i < this->currentSize; i++)
    {
        for(int j = 0; j < this->currentSize; j++)
        {
            (*(this->m + i) + j)->GetPlace() = value;
        }
    }
}
// Node* Map::FindNear(Node& n, int angle)
// {
//     switch (angle)
//     {
//         case 0: return this->getNode(n.GetX() + 1, n.GetY());
//         case 90: return this->getNode(n.GetX(), n.GetY() - 1);
//         case 180: return this->getNode(n.GetX() - 1, n.GetY());
//         case 270: return this->getNode(n.GetX(), n.GetY() + 1);
//     }
//     return NULL;
// }