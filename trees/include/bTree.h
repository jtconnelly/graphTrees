#pragma once
#include <string>
#include <trees_export.h>

namespace _
{
    template <typename T>
    class BTreeNode;
}

namespace Boots
{
    template<typename T>
    class TREES_EXPORT BTree {
        static_assert(std::three_way_comparable<T>, "BTrees require the values to be comparable");
    private:

        _::BTreeNode<T>* root; // Pointer to root node
        int t; // Minimum degree
    public:
        // Constructor (Initializes tree as empty)
        BTree(int _t)
        {
            root = nullptr;
            t = _t;
        }

        // function to traverse the tree
        std::string traverse() const;

        // function to search a key in this tree
        bool search(const T& k);
        void insert(const T& k);
        bool remove(const T& k);
    };
}