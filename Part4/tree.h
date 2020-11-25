#ifndef TREE_H
#define TREE_H

#include "treenode.h"

// TODO your code goes here:
template<typename T>
class BinarySearchTree{
    private:
    unique_ptr<TreeNode<T>> root;

    public:
    BinarySearchTree(){}

    void write(ostream& s) const{
        root->write(s);
    }

    TreeNode<T>* insert(T data){
        if(!root){
            TreeNode<T>* rootNode = new TreeNode<T>(data);
            root.reset(rootNode);
            return rootNode;  
        }
        else{
            if (data < root->data){
                if (!root->leftChild){
                    TreeNode<T>* lc = new TreeNode<T>(data);
                    root->setLeftChild(lc);
                    return lc;
                }
                else{
                    if (data < root->leftChild->data){
                    TreeNode<T>* lc = new TreeNode<T>(data);
                    root->leftChild->setLeftChild(lc);
                    return lc;
                    }
                    else if(root->leftChild->data < data){
                    TreeNode<T>* rc = new TreeNode<T>(data);
                    root->leftChild->setRightChild(rc);
                    return rc;    
                    }
                    else {return root->leftChild.get();}
                }
            }
            else if( root->data < data){
                if (!root->rightChild){
                    TreeNode<T>* lc = new TreeNode<T>(data);
                    root->setRightChild(lc);
                    return lc;
                }
                else{
                    if (data < root->rightChild->data){
                    TreeNode<T>* lc = new TreeNode<T>(data);
                    root->rightChild->setLeftChild(lc);
                    return lc;
                    }
                    else if(root->rightChild->data < data){
                    TreeNode<T>* rc = new TreeNode<T>(data);
                    root->rightChild->setRightChild(rc);
                    return rc;    
                    }
                    else {return root->rightChild.get();}
                }
            }
            else {return root.get();}
        }

    }

    TreeNode<T>* find(T data){
        TreeNode<T>* mynode = nullptr;
        if(!root){
            return mynode;  
        }
        else{
            if (data < root->data){
                if (!root->leftChild){
                    return mynode;
                }
                else{
                    if (data < root->leftChild->data){
                        if(data == root->leftChild->leftChild->data){
                            return root->leftChild->leftChild.get();
                        }
                        else{return mynode;}
                    }
                    else if(root->leftChild->data < data){
                        if(data == root->leftChild->rightChild->data){
                            return root->leftChild->rightChild.get();
                        }
                        else{return mynode;}                      
                    }
                    else {return root->leftChild.get();}
                }
            }
            else if( root->data < data){
                if (!root->rightChild){
                    return mynode;
                }
                else{
                    if (data < root->rightChild->data){
                        if(data == root->rightChild->leftChild->data){
                            return root->rightChild->leftChild.get();
                        }
                        else{return mynode;}
                    }
                    else if(root->rightChild->data < data){
                        if(data == root->rightChild->rightChild->data){
                            return root->rightChild->rightChild.get();
                        }
                        else{return mynode;}
                    }
                    else {return root->rightChild.get();}
                }
            }
            else {return root.get();}
        }
    }

/*     BinarySearchTree(const BinarySearchTree& other){
        root = other.root;
    } */
    
};



// do not edit below this line

#endif
