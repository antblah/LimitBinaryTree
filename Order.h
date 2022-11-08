#include <cstddef>


// Forward Declaration
struct Limit;

class Order {
    private:
        int idNumber;
        bool buyOrSell;
        int size;
        int entryTime;
        Order* nextOrder;
        Order* prevOrder;
        Limit *parentLimit;

    public:

        Order() : idNumber(), buyOrSell(), entryTime(), nextOrder(NULL), prevOrder(NULL), parentLimit(NULL) { }

        // Create a new Order to be placed at the Limit price levels
        Order *createNewOrder(int orderNumber, bool orderType, int volume, float orderPriceLevel);
 
};
