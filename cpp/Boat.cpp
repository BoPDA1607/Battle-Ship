#include "D:\PBL2.1\header\Boat.h"
int Boat::boatNums[3] = {3, 4, 5};
int Boat::ListOfBoatSize[5] = {2, 3, 3, 4, 5};
int Boat::SinkBoat = 8; // 2 + 3 + 3
// int Boat::index = 0;

Boat::Boat(const int x0, const int y0, const int ind1, const int ind2) 
    : isSink(0)
{
    this->currentBoatNums = Boat::boatNums[ind2];
    int size = Node::nodeSize[ind1];
    this->p = new Node[this->currentBoatNums];
    for(int i = 0; i < this->currentBoatNums; i++)
    {
        this->boatSize = Boat::ListOfBoatSize[i];
       *(this->p + i) = Node(x0, i + y0, size*x0, i*size + size, size*this->boatSize, size, 0.0f, 0); 
    }
}
Boat::~Boat()
{ 
    delete[] this->p;
}
Boat& Boat::operator=(const Boat& b)
{
    for(int i = 0; i < this->currentBoatNums; i++)
    {
        *(this->p + i) = *(b.p + i);
    }

    return (*this);
}
Boat& Boat::operator()(const int x0, const int y0, const int ind1, const int ind2)
{
    this->isSink = 0;
    int size = Node::nodeSize[ind1];
    this->currentBoatNums = Boat::boatNums[ind2];
    for(int i = 0; i < this->currentBoatNums; i++)
    {
        this->boatSize = Boat::ListOfBoatSize[i];
       *(this->p + i) = Node(x0, i + y0, size*x0, i*size + size, size*this->boatSize, size, 0.0f, 0); 
    }

    return (*this);
}
ostream& operator<<(ostream& o, const Boat& b)
{
    for(int i = 0; i < Boat::boatNums[0]; i++)
    {
        o << *(b.p + i);
    }

    return o;
}
void Boat::DrawBoat(SDL_Renderer& renderer, bool isStart, bool isPlay)
{
    if(!isPlay) return;
    Graphics boat1;
    Graphics boat2;
    Graphics boat3;
    Graphics boat4;
    if(!isStart)
    {
        boat1("images/Ship2.bmp", renderer);
        boat2("images/Ship3.bmp", renderer);
        boat3("images/Ship4.bmp", renderer);
        boat4("images/Ship5.bmp", renderer);
    }
    else
    {
        boat1("images/Ship21.bmp", renderer);
        boat2("images/Ship31.bmp", renderer);
        boat3("images/Ship41.bmp", renderer);
        boat4("images/Ship51.bmp", renderer);
    }
    
    for(int i = 0; i < this->currentBoatNums; i++)
    {
        if(i == 0)
        {
            if((this->p + i)->GetAngle() == 0)
            {
                boat1.Render(renderer, (this->p + i)->getRect(), 0, SDL_FLIP_NONE);
            }
            else
            {
                boat3.Render(renderer, (this->p + i)->getRect(), 0, SDL_FLIP_NONE);
            }
        }
        else
        {
            if((this->p + i)->GetAngle() == 0)
            {
                boat2.Render(renderer, (this->p + i)->getRect(), 0, SDL_FLIP_NONE);
            }
            else
            {
                boat4.Render(renderer, (this->p + i)->getRect(), 0, SDL_FLIP_NONE);
            }
        }
    }

}
Node* Boat::GetBoat(int index)
{
    return &(*(this->p + index));
}
int& Boat::GetisSink()
{
    return this->isSink;
}
void Boat::UpdatePos(const int ind)
{
    for(int i = 0; i < this->currentBoatNums; i++)
    {
        (this->p + i)->UpdatePos(ind);
    }
}
void Boat::ChangePos(const int x0, const int y0, const int ind)
{
    int size = Node::nodeSize[ind];
    for(int i = 0; i < this->currentBoatNums; i++)
    {
        (this->p + i)->ChangePos(x0 + (this->p + i)->GetX(), y0 + (this->p + i)->GetY(), size);
    }
}
void Boat::CheckBoat(SDL_Renderer& renderer, const int size)
{
    Graphics boat1("images/Ship2.bmp", renderer);
    Graphics boat2("images/Ship3.bmp", renderer);
    Graphics boat3("images/Ship4.bmp", renderer);
    Graphics boat4("images/Ship5.bmp", renderer);
    
    for(int i = 0; i < this->currentBoatNums; i++)
    {
        if(i == 0 && (this->p + i)->GetHit() == Boat::ListOfBoatSize[i])
        {
            if((this->p + i)->GetAngle() == 0)
            {
                boat1.Render(renderer, (this->p + i)->getRect(), 0, SDL_FLIP_NONE);
            }
            else
            {
                boat3.Render(renderer, (this->p + i)->getRect(), 0, SDL_FLIP_NONE);
            }
        }
        else if((this->p + i)->GetHit() == Boat::ListOfBoatSize[i])
        {
            if((this->p + i)->GetAngle() == 0)
            {
                boat2.Render(renderer, (this->p + i)->getRect(), 0, SDL_FLIP_NONE);
            }
            else
            {
                boat4.Render(renderer, (this->p + i)->getRect(), 0, SDL_FLIP_NONE);
            }
        }
    }
}
void Boat::PointInBoat(Map& m, const int ind)
{
    for(int i = 0; i < this->currentBoatNums; i++)
    {
        int x = (this->p + i)->GetX() + 1;
        int y = (this->p + i)->GetY() + 1;
        if((this->p + i)->GetAngle() == 0)
        {
            for(int j = 0; j < Boat::ListOfBoatSize[i]; j++)
            {
                cout << "hi";
                m.getNode(x + j, y, 1, 1, ind)->GetPlace() += 1;
            }
        }
        else
        {
            for(int j = 0; j < Boat::ListOfBoatSize[i]; j++)
            {
                m.getNode(x, y + j, 1, 1, ind)->GetPlace() += 1;
            }
        }
    }
}
Node* Boat::GetBoat(const int x, const int y, const int ind)
{
    int size = Node::nodeSize[ind];
    SDL_Point pos = {x*size, y*size};
    for(int i = 0; i < this->currentBoatNums; i++)
    {
        if(SDL_PointInRect(&pos, (this->p + i)->getRect()))
        {
            return (this->p + i);
        }
    }
    return NULL;
}
