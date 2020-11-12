#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

#include <utility>
#include <initializer_list>

// Do not add any #include statements here.  If you have a convincing need for adding a different `#include` please post in the forum on KEATS.

// TODO your code goes here:

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



};


// do not edit below this line

#endif
