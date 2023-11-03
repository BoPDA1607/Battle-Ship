#include "D:\PBL2\header\Boat.h"
int Boat::boatNums = 3;
int Boat::ListOfBoatSize[3] = {2, 3, 3};
// int Boat::index = 0;

Boat::Boat() 
{
    this->p = new Node[this->boatNums];
    for(int i = 0; i < Boat::boatNums; i++)
    {
        this->boatSize = Boat::ListOfBoatSize[i];
       *(this->p + i) = Node(3.0f, float(i + 1), 240, i*Node::nodeSize + 80, Node::nodeSize*this->boatSize, Node::nodeSize); 
    }
}
Boat::Boat(int n)
{
    this->p = new Node[this->boatNums];
    for(int i = 0; i < Boat::boatNums; i++)
    {
        this->boatSize = Boat::ListOfBoatSize[i];
        *(this->p + i) = Node(1.0f, float(i + 1), 80, i*Node::nodeSize + 80, Node::nodeSize*this->boatSize, Node::nodeSize);
    }
}
Boat::~Boat()
{ 
    delete[] this->p;
}
void Boat::DrawBoat(SDL_Renderer& renderer)
{
    Graphics boat1("Ship2.bmp", renderer);
    Graphics boat2("Ship3.bmp", renderer);
    for(int i = 0; i < Boat::boatNums; i++)
    {
        if(i == 0)
        {
            boat1.Render(renderer, (*(this->p + i)).getRect(), (this->p + i)->GetAngle(), SDL_FLIP_NONE);
        }
        else
        {
            boat2.Render(renderer, (*(this->p + i)).getRect(), (this->p + i)->GetAngle(), SDL_FLIP_NONE);
        }
    }

}
Node* Boat::GetBoat(int index)
{
    return &(*(this->p + index));
}
