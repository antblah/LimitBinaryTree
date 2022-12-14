#include "Order.h"
#include "OrderLinkedList.h"
#include "BinaryTree.h"

OrderLinkedList::OrderLinkedList() {              // Constructor 
    header = new Order;
    trailer = new Order;
    header->nextOrder = trailer;
    trailer->prevOrder = header;
}


OrderLinkedList::OrderLinkedList(float priceLevel) {              // Constructor 
    level = priceLevel;
    header = new Order;
    trailer = new Order;
    header->nextOrder = trailer;
    trailer->prevOrder = header;
}

OrderLinkedList::~OrderLinkedList() {
    while (!empty()) {
        removeFront();
    }
    delete header;
    delete trailer;
}

bool OrderLinkedList::empty() const {
    return header->nextOrder == trailer;
}

const int OrderLinkedList::front() const {
    return header->nextOrder->idNumber;
}

const int OrderLinkedList::back() const {
    return trailer->prevOrder->idNumber;
}


void OrderLinkedList::add(Order* v, int e) {            // Insert a new node before v
    Order* u = new Order;
    u->idNumber= e;
    u->nextOrder = v;
    u->prevOrder = v->prevOrder;
    v->prevOrder->nextOrder = v->prevOrder = u;  
}

void OrderLinkedList::addFront(float e) {
    add(header->nextOrder, e);
}

void OrderLinkedList::addBack(float e) {
    add(trailer, e);
}

void OrderLinkedList::addOrderFront(float priceLevel,  Order* v) {
    Order* u = new Order;
    u->idNumber = v->idNumber;
    u->buyOrSell = v->buyOrSell;
    u->size = v->size;
    u->orderPriceLevel = v->orderPriceLevel;
    u->nextOrder = v;
    u->prevOrder = v->prevOrder;
    v->prevOrder->nextOrder = v->prevOrder = u;
}

void OrderLinkedList::remove(Order* v) {
    Order* u = v->prevOrder;
    Order* w = v->nextOrder;
    u->nextOrder = w;
    w->prevOrder =u;
    delete v;
}

void OrderLinkedList::removeFront() {
    remove(header->nextOrder);
}

void OrderLinkedList::removeBack() {
    remove(trailer->prevOrder);
}


int OrderLinkedList::totalSize(Order* v) {
    int size = 0;
    while(v->nextOrder != NULL) {
        size += v->size;
    }
return size;

}

int OrderLinkedList::totalOrders(Order* v) {
    int counter = 0;
    while(v->nextOrder != NULL) {
        ++counter;
    }

return counter;

}


void OrderLinkedList::printOrders() {


}
