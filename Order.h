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
        float orderPriceLevel;
        Order* nextOrder;
        Order* prevOrder;
        Limit *parentLimit;

        friend class OrderLinkedList; 

    public:


        // Create a new Order to be placed at the Limit price levels
        Order();
        Order(int idNumber, bool buyOrSell, int size, float orderPriceLevel);
        Order *createNewOrder(int idNumber, bool buyOrSell, int size, float orderPriceLevel);
};
