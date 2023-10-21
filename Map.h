#include "Node.h"

class Map : protected Node
{
    protected:
        SDL_Rect** m;
        static int mapSize;
    public:
        Map();
        ~Map();
        void drawMap(SDL_Renderer&, SDL_Texture*);
        void Show();
};