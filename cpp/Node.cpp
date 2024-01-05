#include "D:\Battleship-main\header\Node.h"
int Node::nodeSize = 80;
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
void Node::UpdatePos()
{
    this->xVal = (this->rect.x - 240)/Node::nodeSize;
    this->yVal = (this->rect.y - 80)/Node::nodeSize;
}
void Node::ChangePos(const int x, const int y, const int size)
{
    this->rect.x = x*size;
    this->rect.y = y*size;
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
        {
            this->angle = 90;
            this->SwapWH();
        }
    }
    else
    {
        {
            this->angle = 0;
            this->SwapWH();
        }
    }
}
bool Node::InRange(const int x, const int y)
{
    return (x >= 3 && y >= 1
            && x <= 9-(this->rect.w/Node::nodeSize) && y <= 7-(this->rect.h/Node::nodeSize));
}
void Node::SwapWH()
{
    int temp = this->rect.w;
    this->rect.w = this->rect.h;
    this->rect.h = temp;
}
void Node::DrawScreen(SDL_Renderer& rend, bool isStart, bool isPlay)
{
    Graphics gScreen;
    if(!isPlay) return;
    if(!isStart)
    {
        gScreen("images/Map.bmp", rend);
    }
    else 
    {
        gScreen("images/Map1.bmp", rend);
    }
    gScreen.Render(rend, &this->rect, this->angle);
}
void Node::DrawSB(SDL_Renderer& rend, bool isStart, bool isPlay)
{
    Graphics gSB;
    if(!isStart && isPlay)
    {
        gSB("images/start-button.bmp", rend);
    }
    gSB.Render(rend, &this->rect, this->angle);
}
void Node::DrawPB(SDL_Renderer& rend, bool isPlay)
{
    Graphics gPB("images/Play-Button.bmp", rend);
    if(!isPlay)
    {
        gPB.Render(rend, &this->rect, this->angle);
    }
}
void Node::DrawTitle(SDL_Renderer& rend, bool isPlay)
{
    Graphics gT("images/Title-Screen.bmp", rend);
    if(!isPlay)
    {
        gT.Render(rend, &this->rect, this->angle);
    }
    
}
void ShowTurn(SDL_Renderer& rend, bool isStart, int& turn, Node& Pturn, Node& Bturn, Node& Turn, int& isDraw)
{
    if(!isStart) return;
    Graphics gTurn;
    Graphics gTurn1;
    Node whoTurn = Node(-1);

    if(turn == 0)
    {
        gTurn("images/Pturn.bmp", rend);
        gTurn1("images/turn.bmp", rend);
        whoTurn = Pturn;
    }
    gTurn1.Render(rend, whoTurn.getRect());
    if(isDraw++ <= 10)
    {
        gTurn.Render(rend, Turn.getRect());
    }
}