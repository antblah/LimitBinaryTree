#include "Order.h"
#include "OrderLinkedList.h"

OrderLinkedList::OrderLinkedList() {              // Constructor 
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

void OrderLinkedList::addFront(int e) {
    add(header->nextOrder, e);
}
void OrderLinkedList::addBack(int e) {
    add(trailer, e);
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
