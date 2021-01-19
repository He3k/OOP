#include "tree.h"
#include <iostream>

using namespace std;

void SBTree::add_node(int new_key){
    if (key == 0){
        key = new_key;
    }else{
        if (new_key < key){
            if(left == NULL){
                left = new SBTree(new_key);
                left->set_parent(this);
            }
            else
                left->add_node(new_key);
        }else{
            if(right == NULL){
                right = new SBTree(new_key);
                right->set_parent(this);
            }
            else
                right->add_node(new_key);
        }
    }
}

BinaryTree* SBTree::find(int key){
    if(this->key == key){
        return this;
    }
    if(key < this->key && left != NULL){
        return left->find(key);
    }else if(key > this->key && right != NULL){
        return right->find(key);
    }
    return NULL;
}

BinaryTree* SBTree::find_min(){
    if(left == NULL){
        return this;
    }
    return left->find_min();
}

BinaryTree* SBTree::find_max(){
    if(right == NULL){
        return this;
    }
    return right->find_max();
}

void SBTree::delete_node(int deleted_key){
    BinaryTree* deleted = this->find(deleted_key);
    BinaryTree* new_node;
    if(deleted){
        if (deleted->get_left() != NULL || deleted->get_right() != NULL){
            if(deleted->get_left() == NULL){
                new_node = deleted->get_right();
                new_node->get_parent()->set_right(NULL);
            }else if(deleted->get_right() == NULL){
                new_node = deleted->get_left();
                new_node->get_parent()->set_left(NULL);
            }else{
                new_node = left->find_max();
                new_node->get_parent()->set_right(new_node->get_left());
                new_node->set_left(deleted->get_left());
                new_node->set_right(deleted->get_right());
            }
            new_node->set_parent(deleted->get_parent());
            if(deleted->get_parent()->get_left() == deleted){
                deleted->get_parent()->set_left(new_node);
            }else{
                deleted->get_parent()->set_right(new_node);
            }
        }
        delete deleted;
    }
}

void SBTree::traverse(){
    if(left != NULL){
        left->traverse();
    }
    cout << key << endl;
    if(right != NULL){
        right->traverse();
    }
}