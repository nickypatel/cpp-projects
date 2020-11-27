#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

#include <memory>
using std::unique_ptr;

#include <utility>
using std::pair;


// TODO your code for the TreeNode class goes here:
template<typename T>
class TreeNode{
    public:

    T data;
    unique_ptr<TreeNode<T>> leftChild;
    unique_ptr<TreeNode<T>> rightChild;
    TreeNode<T> * parent;

    TreeNode(T dataIn)
    : data(dataIn){
        parent = nullptr;
    }

    void setLeftChild(TreeNode<T>* child){
        leftChild.reset(child);
        child->parent = this;
    }

    void setRightChild(TreeNode<T>* child){
        rightChild.reset(child);
        child->parent = this;
    }

    void write(ostream& s) const{
        if (leftChild){
            leftChild->write(s);
        }
        s << " " << data << " " ;
        if (rightChild){
            rightChild->write(s);
        }        
    }

    int max(int a, int b){
        if (a > b){
            return a;
        }
        else if(a<b){
            return b;
        }
        else{
            return a;
        }

    }
    int maxDepth(){
        if (!leftChild && !rightChild){
            return 1;
        }
        else{
            auto left = leftChild.get();
            auto right = rightChild.get();
            return 1 + max(left->maxDepth(),right->maxDepth());
        }

    }
};

template<typename T>
class TreeNodeIterator{
    
 
    
    
public:
    TreeNode<T>* current;

    TreeNodeIterator(TreeNode<T>* currentIn)
        : current(currentIn) {        
    }

    T & operator*() {
        return current->data;
    }


    TreeNodeIterator<T> operator++(){
       TreeNode<T>* newtn = current;
       do{
            if (newtn->rightChild){

             if(newtn->rightChild.get() != current){
                newtn =newtn->rightChild.get();
             }
            }
            else{
                newtn = newtn->parent;
            }
       }while (newtn->data < current->data);
       current = newtn;
       return current;
    }

    bool operator==(const TreeNodeIterator& other){
        return (current == other.current);
    }    
    
    bool operator!=(const TreeNodeIterator& other){
        return (current != other.current);
    }

    

      
};
// do not edit below this line

#endif
