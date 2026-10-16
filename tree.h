#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value);
};

class Tree {
public:
    Node* root;

    Tree();
    ~Tree();

    Node* insert(Node* n, int v);
    bool search(Node* n, int v);
    Node* findMin(Node* n);
    Node* deleteNode(Node* n, int v);

    void inOrder(Node* n);
    void preOrder(Node* n);
    int height(Node* n);
    void levelOrder();

    void destroy(Node* n);
};

#endif
