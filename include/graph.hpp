#include "graph.h"

// Part1
template <typename T>
void Graph<T>::addVertex(const T& value)
{
    Node* node { new Node {} };
    node->value = value;
    head.push_back(node);
}
template <typename T>
void Graph<T>::addEdge(const T& v1, const T& v2, int a, std::function<bool(T, T)> func)
{
    Node* node1 { nullptr };
    Node* node2 { nullptr };
    for (auto node : head) {
        if (func(node->value, v1))
            node1 = node;
        if (func(node->value, v2))
            node2 = node;
    }

    Node* copy { new Node {} };
    copy->value = node2->value;

    Node* cuurent { node1 };

    if (node1 && node2) {
        while (current->next) {
            current = current->next;
        }
        current->next = copy;
    }
}

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
