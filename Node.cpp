#include "Node.h"

Node::Node(const ItemType& item) {
    this->data = item;
    next = nullptr;
}