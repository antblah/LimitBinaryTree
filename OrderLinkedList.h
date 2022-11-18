#pragma once

class Order;

class OrderLinkedList {

public:
    OrderLinkedList();                      
    ~OrderLinkedList();
    bool empty() const;
    const int front() const;
    const int back() const;
    void addFront(int e);
    void addBack(int e);
    void removeFront();
    void removeBack();
    int totalSize(Order* v);
    int totalOrders(Order* v);
    void printOrders();

private:

    Order* header;
    Order* trailer;

protected:
    void add(Order* v, int e);
    void remove(Order* v);

friend class Order;

};