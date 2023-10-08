#include "Node.h"

class Map
{
    private:
        Node** m;
        static int mapSize;
    public:
        Map();
        Map(const int, const int, SDL_Renderer*);
        ~Map();
};