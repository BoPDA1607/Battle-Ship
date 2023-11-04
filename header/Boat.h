#include "Map.h"
class Boat : protected Map
{
    protected:
        Node* p;
        int boatSize;
    public: 
        static int boatNums;
        static int ListOfBoatSize[3];
    public:
        Boat();
        Boat(const int);
        ~Boat();
        Boat& operator=(const Boat&);
        void DrawBoat(SDL_Renderer&, const int);
        Node* GetBoat(int);
        void UpdatePos();
        void ChangePos(const int, const int, const int);
};