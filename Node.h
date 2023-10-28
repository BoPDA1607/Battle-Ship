#include "Graphics.h"
class Node
{
    protected:
        SDL_Rect rect;
        float angle;
    public:
        static int nodeSize;
    public:
        Node(int = 0, int = 0, int = 0, int = 0, float = 0.0f);
        ~Node();
        bool operator==(const Node&);
        Node& operator=(const Node&);
        Node& operator()(const int, const int);
        SDL_Rect* getRect();
        int GetX();
        int GetY();
        float GetAngle();
        void ChangePos(const int, const int);
        void Rotation(float angle);
};