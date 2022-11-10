#pragma once
#include <string>

typedef std::string Elem;
class DNode {
    private:
        Elem elem;                      // Node element value
        DNode* prev;                    // Pointer to previous element
        DNode* next;                    // Pointer to next element

        friend class DLinkedList;       // Allow DLinkedList access
};


class DLinkedList {

public:
    DLinkedList();                      
    ~DLinkedList();
    bool empty() const;
    const Elem& front() const;
    const Elem& back() const;
    void addFront(const Elem& e);
    void addBack(const Elem& e);
    void removeFront();
    void removeBack();

private:
    DNode* header;
    DNode* trailer;

protected:
    void add(DNode* v, const Elem& e);
    void remove(DNode* v);
};