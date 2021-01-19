#include "tree.h"
#include <iostream>

using namespace std;

int main(){
    SBTree a(15);
    a.add_node(10);
    a.add_node(30);
    a.add_node(20);
    a.add_node(5);
    a.add_node(13);
    cout << "Обход дерева:" << endl;
    a.traverse();
    cout << "Обход дерева после удаления узла 10:" << endl;
    a.delete_node(10);
    a.traverse();
    cout << "Обход дерева после добавления узла 12:" << endl;
    a.add_node(12);
    a.traverse();
    return 0;
}