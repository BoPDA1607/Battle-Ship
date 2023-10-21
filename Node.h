#include "Graphics.h"
class Node
{
    protected:
        //SDL_Rect rect;
        int xVal,yVal;
        float angle;
    public:
        static int nodeSize;
    public:
        Node(int = 0, int = 0);
        ~Node();
        friend ostream& operator<<(ostream&, const Node&);
        bool operator==(const Node&);
        Node& operator=(const Node&);
        Node& operator()(const int, const int);
        SDL_Rect* getRect();
        int GetX();
        int GetY();
};