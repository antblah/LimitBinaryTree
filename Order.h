#pragma once
#include <cstddef>
#include "OrderLinkedList.h"


// Forward Declaration
struct Limit;

class Order {
    private:
        int idNumber;
        bool buyOrSell;
        int size;
        Order* nextOrder;
        Order* prevOrder;
        Limit *parentLimit;

        friend class OrderLinkedList; 

    public:

        Order() : idNumber(), buyOrSell(), size(), nextOrder(NULL), prevOrder(NULL), parentLimit(NULL) { }

        // Create a new Order to be placed at the Limit price levels
        Order *createNewOrder(int idNumber, bool buyOrSell, int size, float orderPriceLevel);
};
