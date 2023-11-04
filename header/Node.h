#include <math.h>
#include "Graphics.h"
class Node
{
    protected:
        int xVal, yVal;
        SDL_Rect rect;
        float angle;
        int isHit;
    public:
        static int nodeSize;
    public:
        Node(int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, float = 0.0f);
        ~Node();
        bool operator==(const Node&);
        Node& operator=(const Node&);
        Node& operator()(const int, const int);
        SDL_Rect* getRect();
        int& GetX();
        int& GetY();
        float GetAngle();
        virtual void UpdatePos();
        virtual void ChangePos(const int, const int, const int);
        int& GetHit();
        void Rotation(float angle);
        virtual bool InRange(const int, const int);
        
};