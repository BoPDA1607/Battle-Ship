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
       *(this->p + i) = Node(3, i + 1, 240, i*Node::nodeSize + 80, Node::nodeSize*this->boatSize, Node::nodeSize); 
    }
}
Boat::Boat(const int size)
{
    this->p = new Node[this->boatNums];
    for(int i = 0; i < Boat::boatNums; i++)
    {
        this->boatSize = Boat::ListOfBoatSize[i];
        *(this->p + i) = Node(1, i + 1, size, i*size + size, size*this->boatSize, size);
    }
}
Boat::~Boat()
{ 
    delete[] this->p;
}
Boat& Boat::operator=(const Boat& b)
{
    for(int i = 0; i < Boat::boatNums; i++)
    {
        (this->p + i)->GetX() = (b.p + i)->GetX();
        (this->p + i)->GetY() = (b.p + i)->GetY();
    }
}
void Boat::DrawBoat(SDL_Renderer& renderer, const int size)
{
    Graphics boat1;
    Graphics boat2;
    if(size == 80)
    {
        boat1("Ship2.bmp", renderer);
        boat2("Ship3.bmp", renderer);
    }
    else
    {
        boat1("Ship21.bmp", renderer);
        boat2("Ship31.bmp", renderer);
    }
    
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
void Boat::UpdatePos()
{
    for(int i = 0; i < Boat::boatNums; i++)
    {
        (this->p + i)->UpdatePos();
    }
}
void Boat::ChangePos(const int x0, const int y0, const int size)
{
    for(int i = 0; i < Boat::boatNums; i++)
    {
        (this->p + i)->ChangePos(x0 + (this->p + i)->GetX(), y0 + (this->p + i)->GetY(), size);
    }
}
