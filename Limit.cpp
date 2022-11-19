#include <cstddef>
#include "Limit.h"

Limit::Limit() : limitPrice(), size(), totalVolume(), parent(NULL), 
            leftChild(NULL), rightChild(NULL), headOrder(NULL), tailOrder(NULL) { } // Constructor

Limit::Limit(float limitPrice, int size, int totalVolume, Limit *parent, Limit *leftChild, Limit *rightChild, Order *headOrder, Order *tailOrder) : 
            limitPrice(limitPrice), size(size), totalVolume(totalVolume), parent(NULL), leftChild(NULL), rightChild(NULL), headOrder(NULL), tailOrder(NULL) { } 



