#include "red-black.h"


namespace Boots
{

    template<typename T>
    void RedBlackTree<T>::insertHelper(TreeNode* node, const T& data)
    {
        enum {
            // (1 == right)
            Left-Left = 0, //00
            Left-Right, // 01
            Right-Left, // 10
            Right-Right // 11
        } flag;
        TreeNode* parent = node->parent;
        TreeNode* grandparent = parent->parent;
        TreeNode* uncle = nullptr; // Important for recoloring
        if (grandparent)
        {
            uncle = (grandparent->left == parent) ? grandparent->right : grandparent->left;
        }
        if (uncle && parent->isRed && uncle->isRed) // Recoloring!
        {
            grandparent->isRed = true;
            uncle->isRed = false;
            uncle->isRed = false;
            // If recoloring causes a problem later that is violated, run insertHelper with grandparent as a node. 
            if (grandparent->parent && grandparent->parent->isRed)
                insertHelper(grandparent);
        }
        if (parent->right == node)
        {
            flag |= 3;
        }
        if (grandparent && grandparent->right == parent)
        {
            flag |= 1;
        }
        switch (flag)
        {
        case 0:
            parent = rotateRight(grandparent);
            parent->isRed = false;
            parent->right->isRed = true;
            break;
        case 1: // 01: Left-Right
            parent = rotateLeft(parent); // new parent = node
            parent->parent = grandparent->parent;
            parent = rotateRight(grandparent);
            parent->isRed = false;
            parent->right->isRed = true;
            break;
        case 2: // 10: Right-Left
            parent = rotateRight(parent);
            parent->parent = grandparent->parent;
            parent = rotateLeft(grandparent);
            parent->isRed = false;
            parent->left->isRed = true;
            break;
        case 3:
            parent = rotateLeft(grandparent);
            parent->isRed = false;
            parent->left->isRed = true;
            break;
        default: // How??
            break;
        }
        root->isRed = false; // Root will always be black regardless of what we do below it
    }

    template<typename T>
    bool RedBlackTree<T>::search(const T& data)
    {
        if (!root)
            return false;
        TreeNode* node = root;
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
        {
            bool needRedo = false;
            TreeNode* newNode = _bstInsert(node, data, needRedo);
            if (!newNode)
                return;
            if (needRedo)
            {
                insertHelper(newNode, data);
            }
        }
            
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