#include "D:\Battleship-main\header\Stack.h"

Stack::Stack()
{
    this->BotHunt=new Node[36];
    this->current=-1;
}

void Stack::Push(Node& n)
{
    if(this->current<36)
    {
        if(n.GetX()!=-1 && n.GetHit() == -1 && this->CheckforDup(n))
        {
            this->current++;
            this->BotHunt[this->current] = n;
        }
    }
    else
    {
        cout<<"Stack full "<<endl;
        return;
    }
}
Node* Stack::Pop()
{
    int check= this->current;
    if(check<0) 
    {
        cout<<"Stack empty "<<endl;
        this->BotHunt=nullptr;
        return NULL;
    }
    else{
        this->current--;
        return &this->BotHunt[check];
    }
}
Stack::~Stack()
{
    delete[] BotHunt;
}
bool Stack::ChechNull(){
    return (this->current > -1);
}
void Stack::MakeNull()
{
    int current= this->current;
    for(;current>-1;current--)
        this->Pop();
}
void Stack::DisplayStack()
{
    int x=this->current;
    for(int i=x;i>=0;i--)
    {
        cout<<this->BotHunt[i].GetX()<<" , " <<this->BotHunt[i].GetY()<<endl;
    }
}
bool Stack::CheckforDup(const Node& n)
{
    if(this->current==-1) return true;
    else 
    {
        int current=this->current;
        for(;current>=0;current--)
            if(this->BotHunt[current]==n) return false;
        return true;
    }
}