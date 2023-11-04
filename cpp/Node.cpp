#include "D:\PBL2\header\Node.h"
int Node::nodeSize = 80;
Node::Node(int xVal, int yVal, int x, int y, int w, int h, float ang)
    : xVal(xVal), yVal(yVal), angle(ang), isHit(-1)
{ 
    this->rect.x = x;
    this->rect.y = y;
    this->rect.w = w;
    this->rect.h = h;
    // this->xVal = x;
    // this->yVal = y;
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
    this->rect.x = n.rect.x;
    this->rect.y = n.rect.y;
    this->rect.w = n.rect.w;
    this->rect.h = n.rect.h;

    return *this;
}
Node& Node::operator()(const int x, const int y)
{
    this->rect.x = x;
    this->rect.y = y;

    return *this;
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
float Node::GetAngle()
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
int& Node::GetHit()
{
    return this->isHit;
}
void Node::Rotation(float angle)
{
    this->angle += angle;
}
bool Node::InRange(const int x, const int y)
{
    return (x >= 3 && y >= 1
            && x <= 9-(this->rect.w/Node::nodeSize) && y <= 6);
}