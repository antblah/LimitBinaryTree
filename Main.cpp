#include <iostream>
#include "BinaryTree.h"


int main() {

    BinaryTree *bidTree = new BinaryTree();
    OrderLinkedList *example = new OrderLinkedList();

    // Receive an Order
    Order one = Order(1, true, 300, 25.50, NULL, NULL, NULL); 
    
    // Search correct Tree for limit
    if (one.buyOrSell == true) {

        //  If order Price Level exists in the Binary Tree
        if(bidTree->isLimit(bidTree->getRoot(), one.orderPriceLevel)) {
                        
            //place Order at tail of the OrderLinkedList
            example->addOrderFront(one.orderPriceLevel, &one);

        } else {

            // Insert new limit into tree at order price level
            bidTree->insert(bidTree->getRoot(), one.orderPriceLevel);

            // Create a linked List at this level
            OrderLinkedList twentyFiveFifty = OrderLinkedList();
            
        } 

    }

    Limit oneL = Limit(25.00, 200, 200, NULL, NULL, NULL, NULL, NULL, NULL);
    
    one.parentLimit = &oneL;
    
    bidTree->insert(bidTree->getRoot(), 43.43);
    bidTree->insert(bidTree->getRoot(), 60.15);
    bidTree->insert(bidTree->getRoot(), 60.35);
    bidTree->insert(bidTree->getRoot(), 50.15);
    bidTree->insert(bidTree->getRoot(), 42.15);
    bidTree->insert(bidTree->getRoot(), 35.00);
    bidTree->insert(bidTree->getRoot(), 20.05);


    
    std::cout << "Buy order book: \n";
    bidTree->inOrder(bidTree->getRoot());
    std::cout << "\n";

    // Limit *test = Limit getLimit(bidTree->getRoot(), 35); 
    //std::cout << test << "\n";

    // delete test;
    delete bidTree;

    return 0;
}