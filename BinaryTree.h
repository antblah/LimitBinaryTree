# pragma once
#include <list>

class LinkedBinaryTree {

    protected:
    
        struct Limit;

        struct Order {
            int idNumber;
            bool buyOrSell;
            int shares;
            int entryTime;
            int eventTime;
            Order* nextOrder;
            Order* prevOrder;
            Limit* parentLimit;

            Order() : idNumber(), buyOrSell(), shares(), entryTime(), eventTime(), nextOrder(NULL),
                prevOrder(NULL), parentLimit(NULL) { } 
        };

        struct Limit {
            int limitPrice;
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


        struct Book {
            Limit *buyTree;
            Limit *sellTree;
            Limit *lowestSell;
            Limit *highestBuy;

            Book() : buyTree(NULL), sellTree(NULL), lowestSell(NULL), highestBuy(NULL) { }
        };

    
    class Position {
        
        private:
            Limit *v;
        
        public:
            Position(Limit *_v); 
            int operator*();
            Position left() const;          
            Position right() const;
            Position parent() const;
            bool isRoot() const;
            bool isExternal() const;
            friend class LinkedBinaryTree;
        
        };

        typedef std::list<Position>PositionList;

    public:
        LinkedBinaryTree();
        int size() const;
        bool empty() const;
        Position root() const;
        PositionList positions() const;
        void addRoot();
        void expandExternal(const Position& p);
        Position removeAboveExternal(const Position& p);


    protected:
        void preorder(Limit* v, PositionList& pl) const;

    private:
        Limit* _root;
        int n;

};