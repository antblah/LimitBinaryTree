#pragma once
#include <cstddef>
#include "OrderLinkedList.h"
#include "Limit.h"

class Order {
    public:    
        int idNumber;
        bool buyOrSell;
        int size;
        float orderPriceLevel;
        Order* nextOrder;
        Order* prevOrder;
        Limit *parentLimit;

        friend class OrderLinkedList; 

        // Create a new Order to be placed at the Limit price levels
        Order();
        
        Order(int idNumber, bool buyOrSell, int size, float orderPriceLevel, Order* nextOrder, Order*prevOrder, Limit* parentLimit);
        
        Order *createNewOrder(int idNumber, bool buyOrSell, int size, float orderPriceLevel);
};
