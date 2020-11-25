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
};
// do not edit below this line

#endif
