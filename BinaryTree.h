#include <cstddef>

// Forward Declaration
struct Limit;                                   

struct Order {
    int idNumber;
    bool buyOrSell;
    int size;
    int entryTime;
    Order* nextOrder;
    Order* prevOrder;
    Limit* parentLimit;

    Order() : idNumber(), buyOrSell(), entryTime(), nextOrder(NULL),
        prevOrder(NULL), parentLimit(NULL) { } 
};

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


class BinaryTree {
    private:
        Limit *root;

    public:
        BinaryTree() { root = NULL; }
        ~BinaryTree();

        
        // Create a new Order to be placed at the Limit price levels
        Order *createNewOrder(int orderNumber, bool orderType, int volume, float orderPriceLevel);

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

};

