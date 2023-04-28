#include <iostream>
#include "Stack.h"

Stack::Stack() {
    this->top = nullptr;
}

void Stack::push(ItemType item) {
    Node* new_node = new Node(item);
    new_node->next = this->top;
    this->top = new_node;
}

Item Stack::pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty. Cannot pop item." << std::endl;
            throw;
    }

    ItemType temp_data = this->top->data;
    Node* node_to_pop = this->top;
    this->top = this->top->next;
        
    delete node_to_pop;
    return temp_data.getData();
}

Item Stack::peek() const {
    if (isEmpty()) {
        std::cout << "Stack is empty. No item to peek." << std::endl;
        throw;
    }

    return this->top->data.getData();
}

bool Stack::isEmpty() const {
    return this->top == nullptr;
}