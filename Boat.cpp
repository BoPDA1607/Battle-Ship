#include "Boat.h"
int Boat::boatNums = 3;
Boat::Boat() //n is number of boats
{
    this->p = new Node*[this->boatNums];
    int ListOfBoatSize[3] = {2, 3, 3};
    for(int i = 0; i < this->boatNums; i++)
    {
        this->boatSize = ListOfBoatSize[i];
        *(this->p + i) = new Node[this->boatSize];
    }
}
Boat::Boat(const char& direction)
{
    this->p = new Node*[this->boatNums];
    this->boatSize = 2;
    for(int i = 0; i < this->boatNums; i++)
    {
        *(this->p + i) = new Node[this->boatSize];
        this->boatSize++;
    }
}
Boat::~Boat()
{ }