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
Node InitNodePos(int i, Map& m,int seed,int x0,int y0 )
{
    srand(time(NULL) *(getpid() + i+seed));
    int x = 0, y = 0, angle = InitBoatAng(i), w, h,
        temp = 7 - Boat::ListOfBoatSize[i];
    if(angle == 0)
    {
        x = x0+ rand() % temp;
        y =  y0+ rand() % 6;
        w = Boat::ListOfBoatSize[i]*Node::nodeSize;
        h = Node::nodeSize;
        if(m.ValidShipPlacement((*m.getNode(x-x0+1,y-y0+1)),Boat::ListOfBoatSize[i],angle) )
        {
            for(int j = 0; j < Boat::ListOfBoatSize[i]; j++)
            {
                m.getNode(x + j-x0+1, y-y0+1)->GetPlace() += 1;
            }                
        }
            else return Node(-1);
    }
    else
    {
        x = x0 + rand() % 6;
        y = y0 + rand() % temp;
        w = Node::nodeSize;
        h = Boat::ListOfBoatSize[i]*Node::nodeSize;
        if(m.ValidShipPlacement((*m.getNode(x-x0+1,y-y0+1)),Boat::ListOfBoatSize[i],angle))
        {
            for(int j = 0; j < Boat::ListOfBoatSize[i]; j++)
            {
                m.getNode(x-x0+1, y + j-y0+1)->GetPlace() += 1;
            }   
        }
        else return Node(-1);
    }
    return Node(x, y, x*Node::nodeSize, y*Node::nodeSize, w, h, angle, 0);
}
int GenPos(int i)
{
    srand(time(NULL) * (getpid() + i));
    return (1 + rand() % 6);
}