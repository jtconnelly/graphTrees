#include "red-black.h"

namespace Boots
{
    template<typename T>
    void RedBlackTree<T>::insertHelper(TreeNode* node, const T& data)
    {

    }

    template<typename T>
    bool RedBlackTree<T>::search(const T& data)
    {
        if (!root)
            return false;
        Node* node = root;
        while (node != nullptr)
        {
            if (node->value == data)
                return true;
            else if (data > node->value)
                node = node->right;
            else if (data < node->value)
                node = node->left;
        }
        return false;
    }

    template<typename T>
    void RedBlackTree<T>::insert(const T& data)
    {
        if (!root)
        {
            root = new TreeNode;
            root->isRed = false;
            root->parent = nullptr;
            root->value = data;
        }
        else
            insertHelper(root, data);
    }

    template<typename T>
    bool RedBlackTree<T>::remove(const T& data)
    {
        return false;
    }

    template<typename T>
    std::string RedBlackTree<T>::toStringHelper(TreeNode* node)
    {
        if (!node)
            return "";
        return toStringHelper(node->left) + node->value + " " + toStringHelper(node->right);
    }

    template<typename T>
    std::string RedBlackTree<T>::toString()
    {
        return toStringHelper(root);
    }
}