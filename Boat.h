#include "Map.h"
class Boat : protected Map
{
    protected:
        SDL_Rect* p;
        int boatSize;
    public: 
        static int boatNums;
        static int ListOfBoatSize[3];
    public:
        Boat();
        ~Boat();
        bool operator==(SDL_Rect&);
        void DrawBoat(SDL_Renderer&, SDL_Rect&, float&, float&, float&);
        SDL_Rect* GetBoat(int);
        void flipBoat(SDL_Renderer&, SDL_Texture*, int, float = 0.0f);
};