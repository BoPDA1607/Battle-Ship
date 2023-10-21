#include "Node.h"
int Node::nodeSize = 80;
Node::Node(int x, int y)
{ 
    // this->rect.x = x;
    // this->rect.y = y;
    // this->rect.w = Node::nodeSize;
    // this->rect.h = Node::nodeSize;
    this->xVal = x;
    this->yVal = y;
}
Node::~Node()
{ 
    // cout << "Huy Node";
}
// ostream& operator<<(ostream& o, const Node& n)
// {   
//     cout << n.rect.x << "," << n.rect.y << " ";
//     return o;
// }
// bool Node::operator==(const Node& n)
// {
//     return (this->rect.x == n.rect.x && this->rect.y == n.rect.y);
// }
// Node& Node::operator=(const Node& n)
// {
//     this->rect.x = n.rect.x;
//     this->rect.y = n.rect.y;
//     this->rect.w = n.rect.w;
//     this->rect.h = n.rect.h;

//     return *this;
// }
Node& Node::operator()(const int x, const int y)
{
    this->xVal = x;
    this->yVal = y;

    return *this;
}
// SDL_Rect* Node::getRect()
// {
//     return &(this->rect);
// }
int Node::GetX()
{
    return this->xVal;
}
int Node::GetY()
{
    return this->yVal;
}