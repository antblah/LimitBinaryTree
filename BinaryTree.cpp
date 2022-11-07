#include <iostream>
#include "BinaryTree.h"

LinkedBinaryTree::Position::Position(Limit* _v = NULL) : v(_v) { };
LinkedBinaryTree::LinkedBinaryTree() : _root(NULL), n(0) { };


//-------------------- MOVE THIS TO RIGHT PLACE

int LinkedBinaryTree::size() const {
    return n;
}


bool LinkedBinaryTree::empty() const {
    return size() == 0;
}

LinkedBinaryTree::Position LinkedBinaryTree::root() const {
    return Position(_root);
}

void LinkedBinaryTree::addRoot() {
    _root = new Limit; n = 1;
}

//---------------------end Move


int LinkedBinaryTree::Position::operator*() {
    return(v->limitPrice); 
}

LinkedBinaryTree::Position LinkedBinaryTree::Position::left() const {
      return Position(v->leftChild);
 }

LinkedBinaryTree::Position LinkedBinaryTree::Position::right() const {
     return Position(v->rightChild);
 }

LinkedBinaryTree::Position LinkedBinaryTree::Position::parent() const {
    return Position(v->parent);
}

bool LinkedBinaryTree::Position::isRoot() const {
    return (v->parent == NULL);
}

bool LinkedBinaryTree::Position::isExternal() const {
    return (v->rightChild == NULL && v->leftChild == NULL);
}

int main() {


    return 0;
}