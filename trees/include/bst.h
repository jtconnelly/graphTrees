#pragma once
#include <compare>
#include <vector>
#include <iostream>
#include <trees_export.h>

namespace Boots
{
    template<typename T>
    class TREES_EXPORT BinarySearchTree
    {
        static_assert(std::three_way_comparable<T>, "Binary Search trees require the values to be comparable");
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        BinarySearchTree(const BinarySearchTree&);
        BinarySearchTree(BinarySearchTree&&);

        const std::vector<T> flatten() const;
        bool insert(const T&);
        const size_t size() const;
        bool remove(const T&);
        bool search(const T&) const;
        const std::vector<T> traverse(const T&) const;
    protected:
        struct Node
        {
            T _value;
            Node* _right = nullptr;
            Node* _left = nullptr;

            Node(const T& v) { _value = v; }
            ~Node()
            {
                delete _right;
                delete _left;
            }
        };
    private:

        bool _insertHelper(Node*, Node*, const T&);
        std::vector<T> _flatten(const Node*) const; 
        

        Node* _root;
        size_t _size;

    };

};
template <typename T>
TREES_EXPORT std::ostream& operator<<(std::ostream& os, const Boots::BinarySearchTree<T>& obj);