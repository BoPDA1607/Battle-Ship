#include "Node.h"
int Node::nodeSize = 80;
Node::Node(int x, int y, int w, int h, float ang)
    : angle(ang)
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
int Node::GetX()
{
    return this->rect.x;
}
int Node::GetY()
{
    return this->rect.y;
}
float Node::GetAngle()
{
    return this->angle;
}
void Node::ChangePos(const int x, const int y)
{
    this->rect.x = x;
    this->rect.y = y;
    
}
void Node::Rotation(float angle)
{
    this->angle += angle;
}