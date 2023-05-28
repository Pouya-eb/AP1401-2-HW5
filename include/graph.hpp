#include "graph.h"

// Part1




// Part2

Node* insert(Node* root, int value)
{
    if (root == nullptr) {
        root = new Node { value };
        return root;
    }
    if (root->value > value)
        root->left = insert(root->left, value);
    else if (root->value < value)
        root->right = insert(root->right, value);

    return root;
}
// void deleteNode(Node* root, int value)


Node* find(Node* root, int value)
{
    if (root == nullptr || root->value == value)
        return root;
    if (value < root->value)
        return find(root->left, value);
    return find(root->right, value);
}
void printInOrder(Node* root)
{
    if (root != nullptr) {
        printInOrder(root->left);
        std::cout << root->value << " ";
        printInOrder(root->right);
    }
}
