#pragma once
#include "ItemType.h"

class Node {
    public:
        ItemType data;
        Node* next;
        Node() {}
        Node(const ItemType&);
};
