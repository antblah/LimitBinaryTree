#include "Order.h"

// Create a new Order
Order *Order::createNewOrder(int orderNumber, bool orderType, int size, float orderPriceLevel) {
    Order *newOrder = new Order();
    newOrder->idNumber = orderNumber;
    newOrder->buyOrSell = orderType;
    newOrder->size = size;
    newOrder->nextOrder == NULL;
    newOrder->prevOrder == NULL;
    //newOrder->parentLimit == NULL;

    return newOrder;
}
