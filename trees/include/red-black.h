#pragma once
#include <trees_export.h>
#include <string>

namespace Boots
{
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
        };

        TreeNode* root;

        void insertHelper(TreeNode* node, const T& data);
        
        std::string toStringHelper(TreeNode* node);

    public:
        RedBlackTree() : root{ nullptr } {}

        bool search(const T& data);
        void insert(const T& data);
        bool remove(const T& data);

        std::string toString();
    };
}