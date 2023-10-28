#include "Map.h"

int Map::mapSize = 6;

Map::Map()
{
    this->m = new Node*[Map::mapSize];
    for(int i = 0; i < Map::mapSize; i++)
    {
        *(this->m + i) = new Node[Map::mapSize];
        for(int j = 0; j < Map::mapSize; j++)
        {
            (*(*(this->m + i) + j)) = Node(j*Node::nodeSize, i*Node::nodeSize, Node::nodeSize, Node::nodeSize);
        }
    }
}
Map::Map(const int x0, const int y0 )
{
    this->m = new Node*[Map::mapSize];
    for(int i = x0; i < x0 + Map::mapSize; i++)
    {
        *(this->m + i) = new Node[Map::mapSize];
        for(int j = y0; j < y0 + Map::mapSize; j++)
        {
            (*(*(this->m + i) + j)) = Node(j*Node::nodeSize, i*Node::nodeSize, Node::nodeSize/2, Node::nodeSize/2);
        }
    }
}
Map::~Map()
{ 
    for(int i = 0; i < Map::mapSize; i++)
    {
        delete[] *(this->m + i);
        // cout << "Xoa Hang";
    }
    delete[] this->m;
    // cout <<"Xoa map";
}
// void Map::Show()
// {
//     for(int i = 0; i < Map::mapSize; i++)
//     {
//         for(int j = 0; j < Map::mapSize; j++)
//         {
//             cout << *(*(this->m + i) + j);
//         }
//         cout << endl;
//     }
// }
void Map::drawMap(SDL_Renderer &renderer)
{
    //Load  image
    // if((*(*(this->m + 5) + 5)).getRect()->w == 80)
    // {
    Graphics m1("Node.bmp", renderer);
    // }
    // else
    // {
    //     m1 = Graphics("Nodev1.bmp", renderer);
    // }

    //Draw image on screen
    for(int i = 0; i < Map::mapSize; i++)
    {
        for(int j = 0; j < Map::mapSize; j++)
        {
            m1.Render(renderer, (*(*(this->m + i) + j)).getRect(), 0, SDL_FLIP_NONE);
        }
    }
}