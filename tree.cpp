#include "tree.h"

Node::Node(int value) {
    data = value;
    left = nullptr;
    right = nullptr;
}


Tree::Tree() {
    root = nullptr;
}


Node* Tree::insert(Node* n, int v) {
    if (n == nullptr) {
        return new Node(v);
    }

    if (v < n->data) {
        n->left = insert(n->left, v);
    }
    else if (v > n->data) {
        n->right = insert(n->right, v);
    }

    return n;
}


bool Tree::search(Node* n, int v) {
    if (n == nullptr) {
        return false;
    }

    if (n->data == v) {
        return true;
    }

    if (v < n->data) {
        return search(n->left, v);
    }

    return search(n->right, v);
}

Node* Tree::findMin(Node* n) {
    while (n != nullptr && n->left != nullptr) {
        n = n->left;
    }

    return n;
}

Node* Tree::deleteNode(Node* n, int v) {
    if (n == nullptr) {
        return nullptr;
    }

    if (v < n->data) {
        n->left = deleteNode(n->left, v);
    }
    else if (v > n->data) {
        n->right = deleteNode(n->right, v);
    }
    else {
    
        if (n->left == nullptr && n->right == nullptr) {
            delete n;
            return nullptr;
        }


        else if (n->left == nullptr) {
            Node* temp = n->right;
            delete n;
            return temp;
        }


        else if (n->right == nullptr) {
            Node* temp = n->left;
            delete n;
            return temp;
        }

        else {
            Node* temp = findMin(n->right);
            n->data = temp->data;
            n->right = deleteNode(n->right, temp->data);
        }
    }

    return n;
}

Left, Root, Right
void Tree::inOrder(Node* n) {
    if (n != nullptr) {
        inOrder(n->left);
        cout << n->data << " ";
        inOrder(n->right);
    }
}

Root, Left, Right
void Tree::preOrder(Node* n) {
    if (n != nullptr) {
        cout << n->data << " ";
        preOrder(n->left);
        preOrder(n->right);
    }
}

int Tree::height(Node* n) {
    if (n == nullptr) {
        return -1;
    }

    int leftHeight = height(n->left);
    int rightHeight = height(n->right);

    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    }

    return rightHeight + 1;
}

void Tree::levelOrder() {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }

        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

void Tree::destroy(Node* n) {
    if (n != nullptr) {
        destroy(n->left);
        destroy(n->right);
        delete n;
    }
}

Tree::~Tree() {
    destroy(root);
}
