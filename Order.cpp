#include "Order.h"

// Create a new Order
Order *Order::createNewOrder(int orderNumber, bool orderType, int volume, float orderPriceLevel) {
    Order *newOrder = new Order();
    newOrder->idNumber = orderNumber;
    newOrder->buyOrSell = orderType;
    newOrder->size = volume;
    newOrder->entryTime = 0;
    newOrder->nextOrder == NULL;
    newOrder->prevOrder == NULL;
    //newOrder->parentLimit == NULL;

    return newOrder;
}
