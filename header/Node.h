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
        static int nodeSize[3];
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
        virtual void UpdatePos(const int);
        virtual void ChangePos(const int, const int, const int);
        void ChangeXPos(const int);
        int& GetPlace();
        int& GetHit();
        void Rotation();
        virtual bool InRange(const int, const int, const int);
        bool InRange(const int);
        void SwapWH();
        void ShowScreen(SDL_Renderer&, bool, bool, bool, const int);
        void ShowSB(SDL_Renderer&, bool, bool, bool);
        void ShowPB(SDL_Renderer&, bool, bool);
        void ShowOB(SDL_Renderer&, bool);
        void ShowTitle(SDL_Renderer&, bool, bool);
        void SlideButton(SDL_Renderer&, bool);
};
#endif