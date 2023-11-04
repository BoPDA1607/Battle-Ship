#include "Node.h"

class Map : protected Node
{
    protected:
        Node** m;
        static int mapSize;
    public:
        Map();
        Map(const int);
        ~Map();
        Node* getNode(const int, const int);
        void checkMap(SDL_Renderer&);
        bool InRange(const int, const int);
};