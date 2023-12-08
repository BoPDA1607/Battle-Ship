#ifndef Boat_h
#define Boat_h
#include "Map.h"
class Boat : protected Map
{
    protected:
        Node* p;
        int boatSize;
        int isSink;
        int currentBoatNums;
    public: 
        static int boatNums[3];
        static int ListOfBoatSize[5];
        static int SinkBoat;
    public:
        Boat(const int, const int, const int, const int);
        ~Boat();
        Boat& operator=(const Boat&);
        Boat& operator()(const int, const int, const int, const int);
        friend ostream& operator<<(ostream&, const Boat&);
        void DrawBoat(SDL_Renderer&, bool, bool);
        Node* GetBoat(int);
        Node* GetBoat(const int, const int, const int);
        int& GetisSink();
        void UpdatePos(const int);
        void ChangePos(const int, const int, const int);
        void CheckBoat(SDL_Renderer&, const int);
        void PointInBoat(Map&, const int);
};
#endif