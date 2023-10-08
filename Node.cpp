#include "Node.h"
int Node::nodeSize = 80;
Node::Node(int x, int y)
    :xVal(x), yVal(y)
{ }
Node::~Node()
{ }
bool Node::operator==(const Node& n)
{
    return (this->xVal == n.xVal && this->yVal == n.yVal);
}
Node& Node::operator=(const Node& n)
{
    this->xVal = n.xVal;
    this->yVal = n.yVal;

    return *this;
}
Node& Node::operator()(const int x, const int y)
{
    this->xVal = x;
    this->yVal = y;

    return*this;
}