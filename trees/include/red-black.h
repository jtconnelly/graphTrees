#pragma once
#include <trees_export.h>
#include <string>

namespace Boots
{
    // Rules: 
    // 1 - Root Node alwaus black
    // 2 - Every node is red when first added
    // 3 - If new node's parent is black, nothing needs to be done
    // 4 - If new node's parent is red, will have to handle by either recoloring or rotating
    // 
    //
    template <typename T>
    class TREES_EXPORT RedBlackTree
    {
    private:
        struct TreeNode
        {
            T value;
            TreeNode* parent;
            bool isRed;
            TreeNode* left = nullptr;
            TreeNode* right = nullptr;
            ~TreeNode()
            {
                delete parent;
                delete left;
                delete right;
            }
        };

        TreeNode* root;

        TreeNode* _bstInsert(TreeNode* node, const T& data, bool& needRedo)
        {
            if (thisNode == nullptr)
            {
                thisNode = new TreeNode;
                thisNode->value = data;
                thisNode->isRed = true;
                if (thisNode->parent && thisNode->parent->isRed)
                {
                    needRedo = true;
                }
                if (thisNode->_value < thisNode->parent->_value)
                {
                    thisNode->parent->_left = thisNode;
                }
                else if (thisNode->_value > thisNode->parent->_value)
                {
                    thisNode->parent->_right = thisNode;
                }
                _size++;
                return thisNode;
            }
            if (thisNode->_value == data)
            {
                return nullptr;
            }
            else if (thisNode->_value > val)
                return _insertHelper(thisNode->_left, val);
            else if (thisNode->_value < val)
                return _insertHelper(thisNode->_right, val);
        }

        void insertHelper(TreeNode* node, const T& data);
        
        std::string toStringHelper(TreeNode* node);

    public:
        RedBlackTree() : root{ nullptr } {}
        ~RedBlackTree() { delete root; }

        bool search(const T& data);
        void insert(const T& data);
        bool remove(const T& data);

        std::string toString();

    private:
        // Function to perform Left Rotation
        TreeNode* rotateLeft(Node* node) {
            TreeNode* x = node->right;
            TreeNode* y = x->left;
            x->left = node;
            node->right = y;
            node->parent = x;
            if (y != nullptr)
                y->parent = node;
            return x;
        }

        // Function to perform Right Rotation
        TreeNode* rotateRight(Node* node) {
            TreeNode* x = node->left;
            TreeNode* y = x->right;
            x->right = node;
            node->left = y;
            node->parent = x;
            if (y != nullptr)
                y->parent = node;
            return x;
        }
    };
}