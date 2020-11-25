#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

#include <utility>
#include <initializer_list>

// Do not add any #include statements here.  If you have a convincing need for adding a different `#include` please post in the forum on KEATS.

// TODO your code goes here:

template<typename U>
class NodeIterator2 {
  
  
private:
    
    Node<U>* current;
    
public:
    

    NodeIterator2(Node<U>* currentIn)
        : current(currentIn) {        
    }

    U & operator*() {
        return current->data;
    }

    // TODO: complete the code for NodeIterator here

    NodeIterator2<U> operator++(){
       current = current->next;
        return current;
    }
    bool operator==(const NodeIterator2& other){
        return (current == other.current);
    }    
    
    bool operator!=(const NodeIterator2& other){
        return (current != other.current);
    }    
    
    Node<U>* getNodePtr(){
        return current;
    }
};

template<typename T>
class LinkedList{

    private:
    Node<T>* head;
    Node<T>* tail;
    unsigned int count;
    
    public:

    LinkedList(){
        count = 0;
        head = nullptr, tail = nullptr;
    }
    
    void push_front(T newfront){
        Node<T>* newhead = new Node<T>(newfront); 
        
        if(count == 0){
            head = tail = newhead;
        }
        else{
        newhead->next = head;
        head->previous = newhead;
        head = newhead;
        }
        ++count;
    }

    T & front(){
       
        return head->data;
       
    }

    void push_back(T newback){
        Node<T>* newtail = new Node<T>(newback); 
        if(count == 0){
            head = tail = newtail;
        }
        else{
        newtail->previous = tail;
        tail->next = newtail;
        tail= newtail;
        }
        ++count;
        
    }

    T & back(){
       
        return tail->data;
       
    }
    
     const unsigned int & size() const{
         return count;
     }  

    NodeIterator<T>  begin(){
        NodeIterator<T> itr(head);
        return itr;
    }

    NodeIterator<T>  end(){
        NodeIterator<T> itr = nullptr;
        return itr;
    }

    ~LinkedList(){
        Node<T>* current = head;
        while (current!= nullptr)
        {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        
    }

    void reverse(){
       Node<T>* current = head;

       while (current!= nullptr)
       {
           Node<T>* temp = current->next;
           current->next = current->previous;
           current->previous = temp;
           current = temp;

       }
        Node<T>* temp2 = tail;
        tail = head;
        head = temp2;

 
    }

    LinkedList(std::initializer_list<T> initlist){
        head = nullptr;
        tail = nullptr;
        count = 0;
        for(auto& e: initlist){
            push_back(e);
        }
    }

    NodeIterator<T> insert(NodeIterator<T> & itr, T element){
        Node<T>* newNode = new Node<T> (element);
        Node<T>* temp = itr.getNodePtr();

        newNode->previous = temp->previous;
        newNode->next = temp;
        temp->previous = newNode;
        if(temp != head){
            Node<T>* temp2 = newNode->previous;
            temp2->next = newNode;
        }
        
        NodeIterator<T> newitr(newNode);

         return newitr;
    }

    NodeIterator<T> erase (NodeIterator<T> itr){
        Node<T>* temp = itr.getNodePtr();
        Node<T>* previous = temp->previous;
        Node<T>* next = temp->next;
        if (temp->next != nullptr)
        {
            next->previous = previous;
        }
        
        if (temp->previous!= nullptr){
           
           previous->next = temp->next;
        }
        delete temp;

        NodeIterator<T> newitr(next);
        return newitr;
    }

    NodeIterator2<T>  begin() const{
        NodeIterator2<T> itr(head);
        return itr;
    }

    NodeIterator2<T>  end() const{
        NodeIterator2<T> itr = nullptr;
        return itr;
    }


};


// do not edit below this line

#endif
