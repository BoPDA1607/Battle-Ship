#include "Boat.h"

Node* ReturnBoat(SDL_Point& mpos, Boat& b, bool& boolean, int i)
{
    if(!boolean && SDL_PointInRect(&mpos, b.GetBoat(i)->getRect()))
    {
        return b.GetBoat(i);
    }
    return NULL;
}
Node* MoveBoat(Boat& b, bool& boolean, SDL_Point& mpos)
{
    for(int i = 0; i < Boat::boatNums[0]; i++)
    {
        if((ReturnBoat(mpos, b, boolean, i)) != NULL) return ReturnBoat(mpos, b, boolean, i);
    }
    return NULL;
}
bool UpdateBoatPos(Boat& b, bool& boolean, Map& m, Map& mPlacing, int& turn, int x0, int y0, const int ind1, const int ind2)
{
    b.UpdatePos(ind2);
    cout << "lm";
    //Set place value in map
    b.PointInBoat(mPlacing, ind1);
    cout << "lma";
    bool check = mPlacing.PlaceInMap();
    //Check if place boat in map is valid
    if(check)
    {
        cout << "lmai";
        boolean = true;
        b.ChangePos(x0, y0, ind2);
        b.PointInBoat(m, ind1);
        if(turn == 0)
            turn = 1;
        else
            turn = 0;
    }
    else
    {
        cout << "WARNING: DAT TAU` TRUNG` ROI` KIA`";
    }

    mPlacing.SetDefault(0);

    return check;
}
SDL_Window* CreateNewWindow(int& w, int& h)
{
    return SDL_CreateWindow("Battle Ship",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
}
void UpdNodeVal(Node& shoot, Node& rect, int& turn, Boat& b, const int ind)
{
    if(shoot.GetPlace() == 1 && shoot.GetHit() == -1)
    {
        shoot.GetHit() = 1;
        rect = *(b.GetBoat(shoot.GetX(), shoot.GetY(), ind));
        rect.GetHit() += 1;
        b.GetisSink() += 1;
        if(turn == 0)
            turn = 1;
        else 
            turn = 0;
    }
    else if(shoot.GetHit() == -1)
    {
        shoot.GetHit() = 0;
        if(turn == 0)
            turn = 1;
        else 
            turn = 0;
    }
}
SDL_Window* ResizeWindow(bool check, int& w, int& h, bool& leftBDown)
{
    if(check)
    {
        //Change window size
        if(w == 1000)
            w = 1290;
        else
            w = 1000;
        leftBDown = false;
        //Create new window
        return CreateNewWindow(w, h);
    }
    return NULL;
}
void ReplayOrHome(bool& replay, bool& home, bool& PlayGame, bool& StartGame, bool& save, bool& win, bool& endGame,
                    Boat& b1, Boat& b2, Map& m1, Map& m2, const int ind1, const int ind2)
{
    if(replay)
        PlayGame = true;
    else if(home)
        PlayGame = false;
    StartGame = false;
    save = false;
    win = false;
    b1(3, 1, ind1, ind2);
    b2(3, 1, ind1, ind2);

    m1(1, 1, ind1);
    m2(9, 1, ind1);
    endGame = false;
}
void InitGameEntity(Boat& b1, Boat& b2, Map& m1, Map& m2, Map& m3, const int ind1, const int ind2)
{
    b1(3, 1, ind1, ind2);
    b2(3, 1, ind1, ind2);

    m1(1, 1, ind1);
    m2(9, 1, ind1);
    m3(3, 1, ind1);
}
void PlacingBoat(int& turn, int& first, Boat& b1, Boat& b2, SDL_Point& mpos, bool& save, bool& start)
{

}
