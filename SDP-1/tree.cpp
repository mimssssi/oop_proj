#include "tree.hpp"

node::node(const int& data, node* child = nullptr, node* sibling = nullptr)
    : data(data), child(child), sibling(sibling)
{}

node* Tree::copy(node* root)
{
    return root ?
        new node(root->data, copy(root->child), copy(root->sibling)) :
        root;
}

void Tree::clear(node* root)
{
    if (root) {
        clear(root->child);
        clear(root->sibling);
        delete root;
    }
}

size_t Tree::height(const node* root) const
{
    if (!root) return 0;
    return std::max(1+height(root->child), height(root->sibling));
}