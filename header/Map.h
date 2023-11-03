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
};