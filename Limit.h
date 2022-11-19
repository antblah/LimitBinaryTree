#pragma once
class Order;

class Limit {

    public:
        float limitPrice;
        int size;
        int totalVolume;
        Limit *parent;
        Limit *leftChild;
        Limit *rightChild;
        Order *headOrder;
        Order *tailOrder;


    Limit();

    Limit(float limitPrice, int size, int totalVolume, Limit *parent, 
            Limit *leftChild, Limit *rightChild, Order *headOrder, Order *tailOrder);

};
                           