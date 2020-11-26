#ifndef TREEMAP_H
#define TREEMAP_H

#include "tree.h"

template<typename Key, typename Value>
class KeyValuePair {
    
public:
    
    const Key k;
    Value v;
    
    // TODO your code for KeyValuePair goes here
    
    KeyValuePair(Key k1, Value v1)
    : k(k1), v(v1) {}

    KeyValuePair(Key k1)
    : k(k1) {}
    
     bool operator< (const KeyValuePair<Key,Value>& kv1) const{
     return (k < kv1.k);
    }
    
};



template<typename Key, typename Value>
ostream & operator<< (ostream & o, const KeyValuePair<Key,Value> & kv){
    o << kv.k << "," << kv.v;
    return o;
}



template<typename Key, typename Value>
class TreeMap {
  
private:
    BinarySearchTree<KeyValuePair<Key,Value> > tree;
    
public:
    
    KeyValuePair<Key,Value> * insert(const Key & k, const Value & v) {
        return &(tree.insert(KeyValuePair<Key,Value>(k,v))->data);
    }
    
    void write(ostream & o) const {
        tree.write(o);
    }
    
    // TODO your code for TreeMap goes here:
    
   KeyValuePair<Key,Value>* find(const Key& k){
       KeyValuePair<Key,Value> kv(k);
       if (tree.find(kv)!=nullptr){
       return &(tree.find(kv)->data);
       }
       else {return nullptr;}
   } 
    
    
};


// do not edit below this line

#endif
