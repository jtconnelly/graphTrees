#pragma once
#include <compare>
#include <vector>

namespace Boots
{
    template<typename T>
    class BinarySearchTree
    {
        static_assert(std::three_way_comparable<T>, "Binary Search trees require the values to be comparable");
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        BinarySearchTree(const BinarySearchTree&);
        BinarySearchTree(BinarySearchTree&&);

        bool insert(const T&);
        const size_t size() const;
        bool remove(const T&);
        bool search(const T&);
        const std::vector<T> traverse(const T&);
    private:
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

        bool _insertHelper(Node*, const T&);

        Node* _root;
        size_t _size;

    };
};