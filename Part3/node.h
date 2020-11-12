#ifndef NODE_H
#define NODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

// Do not add any #include statements here.  If you have a convincing need for adding a different `#include` please post in the forum on KEATS.

// TODO your code for the Node class goes here:
// (Note the 'NodeIterator' class will report lots of errors until Node exists
template<typename U>
class Node {
    
    public:
    
    U data;
    Node<U> * next;
    Node<U> * previous;

    Node (U dataIn)
    : data(dataIn){
        next = NULL, previous = NULL;
    }
};


template<typename T>
class NodeIterator {
  
private:
    
    Node<T>* current;
    
public:
    

    NodeIterator(Node<T>* currentIn)
        : current(currentIn) {        
    }

    T & operator*() {
        return current->data;
    }

    // TODO: complete the code for NodeIterator here

    NodeIterator<T> operator++(){
       current = current->next;
        return current;
    }
    bool operator==(const NodeIterator& other){
        return (current == other.current);
    }    
    
    bool operator!=(const NodeIterator& other){
        return (current != other.current);
    }    
    
    Node<T>* getNodePtr(){
        return current;
    }
};

// do not edit below this line

#endif
