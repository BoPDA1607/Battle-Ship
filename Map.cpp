#include "Map.h"

int Map::mapSize = 6;

Map::Map()
{
    this->m = NULL;
}
Map::Map(const int w, const int h, SDL_Renderer* renderer)
{
    this->m = new Node*[this->mapSize];
    for(int i = 0; i < this->mapSize; i++)
    {
        *(this->m + i) = new Node[this->mapSize];
    }
}
Map::~Map()
{ }