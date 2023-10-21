#include "Boat.h"
int Boat::boatNums = 3;
int Boat::ListOfBoatSize[3] = {2, 3, 3};
// int Boat::index = 0;

Boat::Boat() 
{
    this->p = new SDL_Rect[this->boatNums];
    for(int i = 0; i < Boat::boatNums; i++)
    {
        this->boatSize = Boat::ListOfBoatSize[i];
        // *(this->p + i) = new SDL_Rect[this->boatSize];

        (*(this->p + i)).x = i*Node::nodeSize + 500;
        (*(this->p + i)).y = i*Node::nodeSize + 200;
        (*(this->p + i)).w = Node::nodeSize*this->boatSize;
        (*(this->p + i)).h = Node::nodeSize;

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
void Boat::DrawBoat(SDL_Renderer& renderer, SDL_Rect& rect, float& angle1, float& angle2, float& angle3)
{
    Graphics boat1("Ship2.bmp", renderer);
    Graphics boat2("Ship3.bmp", renderer);
    // if((this->p + 0)->x == rect.x && (this->p + 0)->y == rect.y
    //     && (this->p + 0)->w == rect.w && (this->p + 0)->h == rect.h)
    // {
    //     cout<<"hello";
    // }
    boat1.Render(renderer, &(*(this->p + 0)), angle1, SDL_FLIP_NONE);
    // if((this->p + 1)->x == rect.x && (this->p + 1)->y == rect.y
    //     && (this->p + 1)->w == rect.w && (this->p + 1)->h == rect.h && count == 2)
    // {
    //     angle2 = 90;
    // }
    boat2.Render(renderer, &(*(this->p + 1)), angle2, SDL_FLIP_NONE);
    // if((this->p + 2)->x == rect.x && (this->p + 2)->y == rect.y
    //     && (this->p + 2)->w == rect.w && (this->p + 2)->h == rect.h && count == 2)
    // {
    //     angle3 = 90;
    // }
    boat2.Render(renderer, &(*(this->p + 2)), angle3, SDL_FLIP_NONE);
}
SDL_Rect* Boat::GetBoat(int index)
{
    return &(*(this->p + index));
}