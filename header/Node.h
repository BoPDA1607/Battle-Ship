#include <math.h>
#include "Graphics.h"
class Node
{
    protected:
        float xVal, yVal;
        SDL_Rect rect;
        float angle;
        bool isHit;
    public:
        static int nodeSize;
    public:
        Node(float = 0.0f, float = 0.0f, int = 0, int = 0, int = 0, int = 0, float = 0.0f);
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
        bool& GetHit();
        void Rotation(float angle);
        bool InRange(const int, const int);
        
};