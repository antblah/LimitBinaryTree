#pragma once
#include <iostream>
#include <cstddef>
#include "Order.h"

class BinaryTree {

    public:
        struct Limit {
            float limitPrice;
            int size;
            int totalVolume;
            Limit *parent;
            Limit *leftChild;
            Limit *rightChild;
            Order *headOrder;
            Order *tailOrder;

            Limit() : limitPrice(), size(), totalVolume(), parent(NULL), 
                    leftChild(NULL), rightChild(NULL), headOrder(NULL), tailOrder(NULL) { } // Constructor  
        }; 


        BinaryTree() { root = NULL; }
        ~BinaryTree();

        // Create a new Limit Node
        Limit *createNewLimit(float priceLevel);

        
        // In-order traversal binary search tree
        void inOrder(Limit *limit);


        // Insert new Limit price level on binary tree
        void insert(Limit *limit, float priceLevel);


        // Get root
        Limit *getRoot();

        // Free memory
        void freeMemory(Limit *limit);


    private:
        Limit *root;

};
