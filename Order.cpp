#include "Order.h"

// Order Constructor
Order::Order() : idNumber(), buyOrSell(), size(), nextOrder(NULL), prevOrder(NULL), parentLimit(NULL) { }

Order::Order(int idNumber, bool buyOrSell, int size, float orderPriceLevel) : 
    idNumber(idNumber), buyOrSell(buyOrSell), size(size), orderPriceLevel(orderPriceLevel) { }



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
