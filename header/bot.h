#include "Boat.h"

int InitBoatAng(int i)
{
    srand(time(NULL) * (getpid() + i));
    int angle = rand() % 91 * 2;
    if(angle >= 90)
        angle = 90;
    else
        angle = 0;
    return angle;
}
Node InitNodePos(int i)
{
    srand(time(NULL) *(getpid() + i));
    int x = 0, y = 0, angle = InitBoatAng(i), w, h,
        temp = 7 - Boat::ListOfBoatSize[i];
    if(angle == 0)
    {
        x = 1 + rand() % temp;
        y = 1 + rand() % 6;
        w = Boat::ListOfBoatSize[i]*Node::nodeSize;
        h = Node::nodeSize;
    }
    else
    {
        x = 1 + rand() % 6;
        y = 1 + rand() % temp;
        w = Node::nodeSize;
        h = Boat::ListOfBoatSize[i]*Node::nodeSize;
    }

    return Node(x, y, x*Node::nodeSize, y*Node::nodeSize, w, h, angle, 0);
}
int GenPos(int i)
{
    srand(time(NULL) * (getpid() + i));
    return (1 + rand() % 6);
}


