#include "Map.h"
class Boat : protected Map
{
    protected:
        Node* p;
        int boatSize;
        int isSink;
    public: 
        static int boatNums;
        static int ListOfBoatSize[3];
        static int SinkBoat;
    public:
        Boat(const int, const int, const int);
        ~Boat();
        Boat& operator=(const Boat&);
        Boat& operator()(const int, const int, const int);
        friend ostream& operator<<(ostream&, const Boat&);
        void DrawBoat(SDL_Renderer&, bool, bool);
        Node* GetBoat(int);
        int& GetisSink();
        void UpdatePos();
        void ChangePos(const int, const int, const int);
        void CheckBoat(SDL_Renderer&, const int);
        void PointInBoat(Map&);
};