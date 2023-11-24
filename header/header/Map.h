#include "Node.h"

class Map : protected Node
{
    protected:
        Node** m;
        static int mapSize;
    public:
        int isFull;
    public:
        Map();
        Map(const int, const int, const int);
        ~Map();
        Map& operator()(const int, const int, const int);
        Node* getNode(const int, const int);
        void checkMap(SDL_Renderer&, const int, bool&);
        bool InRange(const int, const int);
        bool PlaceInMap();
        void SetDefault(const int);
        Node* FindNear(Node&, int angle);
};