#ifndef TREE_H
#define TREE_H

#include <cstdlib>

class BinaryTree{
    protected:
    int key;
    BinaryTree* parent;
    BinaryTree* left;
    BinaryTree* right;
    public:
    BinaryTree(){
        parent = NULL;
        left = NULL;
        right = NULL;
        key = 0;
    }
    BinaryTree(int new_key) : key(new_key) {
        parent = NULL;
        left = NULL;
        right = NULL;
    }
    virtual ~BinaryTree() {};
    virtual void add_node(int new_key) {};
    virtual void delete_node(int deleted_key) {};
    virtual int get_key(){return key;};
    virtual BinaryTree* find(int key) {};
    virtual BinaryTree* get_right() {return right;};
    virtual BinaryTree* get_left() {return left;};
    virtual BinaryTree* get_parent() {return parent;};
    virtual void set_right(BinaryTree* p) {right = p;};
    virtual void set_left(BinaryTree* p) {left = p;};
    virtual void set_parent(BinaryTree* p) {parent = p;};
    virtual BinaryTree* find_min() {};
    virtual BinaryTree* find_max() {};
    virtual void traverse() {};
};

class SBTree: public BinaryTree{
    public:
    SBTree() : BinaryTree() {};
    SBTree(int new_key) : BinaryTree(new_key) {};
    virtual ~SBTree() {};
    virtual void set_parent(BinaryTree* parent){this->parent = parent;};
    virtual void add_node(int new_key = -1);
    virtual void delete_node(int deleted_key);
    virtual BinaryTree* find(int key);
    virtual BinaryTree* find_min();
    virtual BinaryTree* find_max();
    virtual void traverse();
};

#endif