#pragma once

class Order;
class Limit;

class OrderLinkedList {

public:
    OrderLinkedList();
    OrderLinkedList(float priceLevel);                      
    ~OrderLinkedList();
    bool empty() const;
    const int front() const;
    const int back() const;
    
    void addFront(float e);
    void addBack(float e);
    void addOrderFront(float priceLevel, Order* v);

    void removeFront();
    void removeBack();
    int totalSize(Order* v);
    int totalOrders(Order* v);
    void printOrders();

private:

    Order* header;
    Order* trailer;
    float level;

protected:
    void add(Order* v, int e);
    void remove(Order* v);

friend class Order;

};