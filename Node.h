#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

class Node
{
    private:
        int xVal, yVal;
    public:
        static int nodeSize;
    public:
        Node(int = 0, int = 0);
        ~Node();
        bool operator==(const Node&);
        Node& operator=(const Node&);
        Node& operator()(const int, const int);
};