#include "Node.h"

class Map : protected Node
{
    protected:
        Node** m;
        static int mapSize;
    public:
        Map();
        Map(const int, const int);
        ~Map();
        void drawMap(SDL_Renderer&);
        void Show();
};