#pragma once
#include <iostream>
#include <cstddef>
#include "Order.h"


class Order;

class BinaryTree {

    public:
        BinaryTree() { root = NULL; }
        ~BinaryTree();
        
        
        // Create a new Limit Node
        Limit *createNewLimit(float priceLevel);


        // Does Limit already exist in the book
        bool isLimit(Limit *limit, float priceLevel);
        
        
        
        // In-order traversal binary search tree
        void inOrder(Limit *limit);

        
        // Insert new Limit price level on binary tree
        void insert(Limit *limit, float priceLevel);


        // Get root
        Limit *getRoot();

        // Free memory
        void freeMemory(Limit *limit);

        friend class Limit;

    private:
        Limit *root;

};
