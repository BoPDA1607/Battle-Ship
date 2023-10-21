#include "Map.h"

int Map::mapSize = 6;

Map::Map()
{
    this->m = new SDL_Rect*[Map::mapSize];
    for(int i = 0; i < Map::mapSize; i++)
    {
        *(this->m + i) = new SDL_Rect[Map::mapSize];
        for(int j = 0; j < Map::mapSize; j++)
        {
            (*(*(this->m + i) + j)).x = i*Node::nodeSize;
            (*(*(this->m + i) + j)).y = j*Node::nodeSize;
            (*(*(this->m + i) + j)).w = Node::nodeSize;
            (*(*(this->m + i) + j)).h = Node::nodeSize;
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
void Map::drawMap(SDL_Renderer &renderer, SDL_Texture* n_texture)
{
    //Load  image
    SDL_Surface *Node_map_surface = SDL_LoadBMP("Node.bmp");
    n_texture = SDL_CreateTextureFromSurface(&renderer, Node_map_surface);
    SDL_FreeSurface(Node_map_surface);

    //Draw image on screen
    for(int i = 0; i < Map::mapSize; i++)
    {
        for(int j = 0; j < Map::mapSize; j++)
        {
            SDL_RenderCopy(&renderer, n_texture, NULL, &(*(*(this->m + i) + j)));
        }
    }
}