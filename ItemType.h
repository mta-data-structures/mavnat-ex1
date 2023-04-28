#pragma once
#include "helpers.h"

class ItemType {
    private:
        Item data;

    public:
        inline ItemType() : data({}) {}
        ItemType(Item);
        ItemType(int, int);
        Item getData() const;
        void setData(Item);
    };
