#include "D:\PBL2.1\header\Node.h"
int Node::nodeSize[3] = {80, 60, 48};
Node::Node(int xVal, int yVal, int x, int y, int w, int h, float ang, int hit, int place)
    : xVal(xVal), yVal(yVal), angle(ang), isPlace(place)
{
    this->rect.x = x;
    this->rect.y = y;
    this->rect.w = w;
    this->rect.h = h;
    this->isHit = hit;
}
Node::~Node()
{ 
    // cout << "Huy Node";
}
bool Node::operator==(const Node& n)
{
    return (this->rect.x == n.rect.x && this->rect.y == n.rect.y);
}
Node& Node::operator=(const Node& n)
{
    this->xVal = n.xVal;
    this->yVal = n.yVal;
    this->rect.x = n.rect.x;
    this->rect.y = n.rect.y;
    this->rect.w = n.rect.w;
    this->rect.h = n.rect.h;
    this->angle = n.angle;
    this->isHit = n.isHit;
    this->isPlace = n.isPlace;

    return *this;
}
Node& Node::operator()(const int x, const int y)
{
    this->rect.x = x;
    this->rect.y = y;

    return *this;
}
Node& Node::operator/(const int i)
{
    this->rect.w = this->rect.w/i;
    this->rect.h = this->rect.h/i;

    return (*this);
}
ostream& operator<<(ostream& o, const Node& n)
{
    o << n.rect.w << " " << n.rect.h << endl;
    return o;
}
SDL_Rect* Node::getRect()
{
    return &(this->rect);
}
int& Node::GetX()
{
    return this->xVal;
}
int& Node::GetY()
{
    return this->yVal;
}
float& Node::GetAngle()
{
    return this->angle;
}
void Node::UpdatePos(const int ind)
{
    int size = Node::nodeSize[ind];
    this->xVal = (this->rect.x - 240)/size;
    this->yVal = (this->rect.y - 80)/size;
}
void Node::ChangePos(const int x, const int y, const int ind)
{
    int size = Node::nodeSize[ind];
    this->rect.x = x*size;
    this->rect.y = y*size;
}
void Node::ChangeXPos(const int x)
{
    this->rect.x = x*180 + 93;
}
int& Node::GetPlace()
{
    return this->isPlace;
}
int& Node::GetHit()
{
    return this->isHit;
}
void Node::Rotation()
{
    if(this->angle == 0)
    {
        this->angle = 90;
    }
    else
    {
        this->angle = 0;
    }
}
bool Node::InRange(const int x, const int y, const int ind)
{
    int size = Node::nodeSize[ind];
    return (x >= 3 && y >= 1
            && x <= 9-(this->rect.w/size) && y <= 7-(this->rect.h/size));
}
bool Node::InRange(const int x)
{
    return (x >= 0 && x <= 2);
}
void Node::SwapWH()
{
    int temp = this->rect.w;
    this->rect.w = this->rect.h;
    this->rect.h = temp;
}
void Node::ShowScreen(SDL_Renderer& rend, bool isStart, bool isPlay, bool isSave, const int ind)
{
    if(!isPlay) return;
    Graphics gScreen;
    bool check = (!isSave || !isStart);
    if(ind == 0)
    {
        if(!isSave || !isStart)
            gScreen("images/Map.bmp", rend);
        else if(isStart)
            gScreen("images/Map1.bmp", rend);
    } 
    else if(ind == 1)
    {
        if(!isSave || !isStart)
            gScreen("images/Map8.bmp", rend);
        else if(isStart)
            gScreen("images/Map18.bmp", rend);
    }
    else if(ind == 2)
    {
        if(!isSave || !isStart)
            gScreen("images/Map10.bmp", rend);
        else if(isStart)
            gScreen("images/Map110.bmp", rend);
    }
    gScreen.Render(rend, &this->rect, this->angle);
}
void Node::ShowSB(SDL_Renderer& rend, bool isStart, bool isPlay, bool isSave)
{
    Graphics gSB;
    if(isPlay && !isStart && isSave)
    {
        gSB("images/start-button.bmp", rend);
    }
    else if(isPlay && !isSave)
    {
        gSB("images/save-button.bmp", rend);
    }
    gSB.Render(rend, &this->rect, this->angle);
}
void Node::ShowPB(SDL_Renderer& rend, bool isPlay, bool option)
{
    if(isPlay || option) return;
    Graphics gPB("images/Play-Button.bmp", rend);
    gPB.Render(rend, &this->rect, this->angle);
}
void Node::ShowTitle(SDL_Renderer& rend, bool isPlay, bool option)
{
    if(isPlay) return;
    Graphics gT;
    if(option)
        gT("images/option-screen.bmp", rend);
    else
        gT("images/Title-Screen.bmp", rend);
    gT.Render(rend, &this->rect, this->angle);
    
}
void Node::ShowOB(SDL_Renderer& rend, bool option)
{
    if(option) return;
    Graphics gOB("images/option-button.bmp", rend);
    gOB.Render(rend, &this->rect, this->angle);
}
void Node::SlideButton(SDL_Renderer& rend, bool option)
{
    if(!option) return;
    Graphics gSlB("images/slider-button.bmp", rend);
    gSlB.Render(rend, &this->rect, this->angle);
}