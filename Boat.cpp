#include "Boat.h"
int Boat::boatNums = 3;
int Boat::ListOfBoatSize[3] = {2, 3, 3};
// int Boat::index = 0;

Boat::Boat() 
{
    this->p = new Node[this->boatNums];
    for(int i = 0; i < Boat::boatNums; i++)
    {
        this->boatSize = Boat::ListOfBoatSize[i];
       *(this->p+i) = Node(240, i*Node::nodeSize + 80, Node::nodeSize*this->boatSize, Node::nodeSize); 
    }
}
Boat::Boat(int n)
{
    this->p = new Node[this->boatNums];
    for(int i = 1; i < Boat::boatNums+1; i++)
    {
        this->boatSize = Boat::ListOfBoatSize[i];
        *(this->p + i) = Node(1.0, float(i), 0.0);
    }
}
Boat::~Boat()
{ 
    // for(int i = 0; i < Boat::boatNums; i++)
    // {
    //     delete[] *(this->p + i);
    // }
    delete[] this->p;
}
// bool Boat::operator==(SDL_Rect& rect)
// {
//     return (this->comp_rect.x == rect.x && this->comp_rect.y == rect.y
//              && this->comp_rect.w == rect.w && this->comp_rect.h == rect.h);
// }
void Boat::DrawBoat(SDL_Renderer& renderer, Node& rect)
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
