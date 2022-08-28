#pragma once

#include <iostream>
#include <queue>
#include <string>

struct node
{
    int data;
    node* child;
    node* sibling;

    node(const int& data, node* child = nullptr, node* sibling = nullptr);
};

class Tree
{
private:
    node* root;
    size_t size;
    std::string name;

public:
    Tree() : root(nullptr), size(0) {};

    // ~Tree() { clear(root); }

private:

    // Makes a copy of the subtree
    // Returns a pointer to a newly created object
    node* copy(node* root);
    // Clears the subtree
    void clear(node* root);
    // Returns the height of the subtree
    size_t height(const node* root) const;
};  