#include <math.h>
#include "Graphics.h"
class Node
{
    protected:
        float xVal, yVal;
        SDL_Rect rect;
        float angle;
    public:
        static int nodeSize;
    public:
        Node(int = 0, int = 0, int = 0, int = 0, float = 0.0f);
        Node(float, float, float);
        ~Node();
        bool operator==(const Node&);
        Node& operator=(const Node&);
        Node& operator()(const int, const int);
        SDL_Rect* getRect();
        float GetX();
        float GetY();
        float GetAngle();
        void UpdatePos(const float, const float);
        void ChangePos(const int, const int);
        void Rotation(float angle);
        bool InRange(const int, const int);
        
};