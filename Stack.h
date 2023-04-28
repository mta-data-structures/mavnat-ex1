#pragma once
#include "Node.h"
#include "ItemType.h"


class Stack {
    private:
        Node* top;

    public:
        Stack();
        void push(ItemType);
        Item pop();
        Item peek() const;
        bool isEmpty() const;
        
};
