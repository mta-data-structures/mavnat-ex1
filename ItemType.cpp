#include "ItemType.h"

ItemType::ItemType(Item data) {
    this->data = data;
}

ItemType::ItemType(int n, int y) {
    this->data = { n, y };
}

Item ItemType::getData() const {
    return this->data;
}

void ItemType::setData(Item data) {
    this->data = data;
}