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
        TreeNode<T>* current = root.get();
        if (current == nullptr){
            TreeNode<T>* rootNode = new TreeNode<T>(data);
            root.reset(rootNode);
            return rootNode;  
        }
        else{
            while (current != nullptr){
           
                if(data < current->data){
                    if(!current->leftChild){
                    TreeNode<T>* lc = new TreeNode<T>(data);
                    current->setLeftChild(lc);
                    return lc; 
                    }
                    else{
                        current = current->leftChild.get();
                    }
                }
                else if( current->data < data){
                    if(!current->rightChild){
                    TreeNode<T>* lc = new TreeNode<T>(data);
                    current->setRightChild(lc);
                    return lc; 
                    }
                    else{
                        current = current->rightChild.get();
                    }
                }
                else {
                    return current;
                }
            }
            return current;
        }
    }
 
    TreeNode<T>* find(T data){
        TreeNode<T>* current = root.get();
        if (current == nullptr){
            return current;
        }
        else{
            while (current != nullptr){
           
                if(data < current->data){
                    if(current->leftChild){
                        current = current->leftChild.get();
                    }
                    else{
                        current = nullptr;
                    }
                }
                else if( current->data < data){
                    if(current->rightChild){
                    current = current->rightChild.get();
                    }
                    else{
                        current = nullptr;
                    }
                }
                else {
                    return current;
                }
            }
            return current;
        }
    } 

    BinarySearchTree(const BinarySearchTree<T>& other){
 /*        TreeNode<T>* other_current = other.root.get();
        if (other_current == nullptr){
            return;
        }
        else{
            while (other_current != nullptr){

                if(current){
                    if(current->leftChild){
                    TreeNode<T>* lc = new TreeNode<T>(current->leftChild->data);
                    current->setLeftChild(lc);
                    
                    }
                    else{
                        current = current->leftChild.get();
                    }
                }
                else if( current->data < data){
                    if(!current->rightChild){
                    TreeNode<T>* lc = new TreeNode<T>(data);
                    current->setRightChild(lc);
                    return lc; 
                    }
                    else{
                        current = current->rightChild.get();
                    }
                }
                else {
                    return current;
                }
            }
            return current;
        } */
        if (other.root){
                TreeNode <T>* rootNode = new TreeNode<T>(other.root->data);
                root.reset(rootNode);
            
            if (other.root->leftChild){
                TreeNode<T>* lc = new TreeNode<T>(other.root->leftChild->data);
                root->setLeftChild(lc);
            }

            if (other.root->rightChild){
                TreeNode<T>* lc = new TreeNode<T>(other.root->rightChild->data);
                root->setRightChild(lc);
            }

                if (other.root->leftChild->leftChild){
                    TreeNode<T>* lc = new TreeNode<T>(other.root->leftChild->leftChild->data);
                    root->leftChild->setLeftChild(lc);
                }
                if (other.root->leftChild->rightChild){
                    TreeNode<T>* lc = new TreeNode<T>(other.root->leftChild->rightChild->data);
                    root->leftChild->setRightChild(lc);
                }
                if (other.root->rightChild->leftChild){
                    TreeNode<T>* lc = new TreeNode<T>(other.root->rightChild->leftChild->data);
                    root->rightChild->setLeftChild(lc);
                }
                if (other.root->rightChild->rightChild){
                    TreeNode<T>* lc = new TreeNode<T>(other.root->rightChild->rightChild->data);
                    root->rightChild->setRightChild(lc);
                }                                                    

        }
    }
    
    void operator=(const BinarySearchTree<T>& other){
        if (other.root){
            TreeNode<T>* rootNode = new TreeNode<T>(other.root->data);
            root.reset(rootNode);
            
            if (other.root->leftChild){
                TreeNode<T>* lc = new TreeNode<T>(other.root->leftChild->data);
                root->setLeftChild(lc);
            }

            if (other.root->rightChild){
                TreeNode<T>* lc = new TreeNode<T>(other.root->rightChild->data);
                root->setRightChild(lc);
            }

                if (other.root->leftChild->leftChild){
                    TreeNode<T>* lc = new TreeNode<T>(other.root->leftChild->leftChild->data);
                    root->leftChild->setLeftChild(lc);
                }
                if (other.root->leftChild->rightChild){
                    TreeNode<T>* lc = new TreeNode<T>(other.root->leftChild->rightChild->data);
                    root->leftChild->setRightChild(lc);
                }
                if (other.root->rightChild->leftChild){
                    TreeNode<T>* lc = new TreeNode<T>(other.root->rightChild->leftChild->data);
                    root->rightChild->setLeftChild(lc);
                }
                if (other.root->rightChild->rightChild){
                    TreeNode<T>* lc = new TreeNode<T>(other.root->rightChild->rightChild->data);
                    root->rightChild->setRightChild(lc);
                }                                                    

        }
    }
};



// do not edit below this line

#endif
