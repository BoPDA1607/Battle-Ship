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
            *(*(this->m + i) + j) = Node(0.0f, 0.0f, (j+1)*size, (i+1)*size, size, size, 0.0f);
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
