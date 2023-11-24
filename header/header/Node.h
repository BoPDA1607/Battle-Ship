#ifndef Node_h
#define Node_h
#include <math.h>
#include <time.h>
#include <unistd.h>
#include "Graphics.h"
class Node
{
    protected:
        int xVal, yVal;
        SDL_Rect rect;
        float angle;
        int isHit;
        int isPlace;
    public:
        static int nodeSize;
    public:
        Node(int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, float = 0.0f, int = -1, int = 0);
        ~Node();
        bool operator==(const Node&);
        Node& operator=(const Node&);
        Node& operator()(const int, const int);
        Node& operator/(const int);
        friend ostream& operator<<(ostream&, const Node&);
        SDL_Rect* getRect();
        int& GetX();
        int& GetY();
        float& GetAngle();
        virtual void UpdatePos();
        virtual void ChangePos(const int, const int, const int);
        int& GetPlace();
        int& GetHit();
        void Rotation();
        virtual bool InRange(const int, const int);
        void SwapWH();
        void DrawScreen(SDL_Renderer&, bool, bool isPlay);
        void DrawSB(SDL_Renderer&, bool, bool);
        void DrawPB(SDL_Renderer&, bool);
        void DrawTitle(SDL_Renderer&, bool);
};
#endif