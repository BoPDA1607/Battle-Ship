#include "Node.h"

class Stack
{
    protected:
        Node* BotHunt;
        int current;
    public:
        Stack();
        ~Stack();
        void Push(Node&);
        Node* Pop();
        bool ChechNull();
        void MakeNull();
        void DisplayStack();
};