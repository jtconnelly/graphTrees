#include "bst.h"

namespace Boots
{
    template<typename T>
    BinarySearchTree<T>::BinarySearchTree() 
    {
        _root = nullptr;
        _size = 0;
    }
    template<typename T>
    BinarySearchTree<T>::~BinarySearchTree() 
    {
        delete _root;
    }
    template<typename T>
    BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& tree) 
    {
        _size = tree._size;
        _root = *tree._root;
    }
    

    template<typename T>
    BinarySearchTree<T>::BinarySearchTree(BinarySearchTree&& tree) 
    {
        _size = tree._size;
        _root = tree._root;

        delete tree;
    }



    template<typename T>
    bool BinarySearchTree<T>::_insertHelper(Node* thisNode, const T& val)
    {
        if (thisNode == nullptr)
        {
            thisNode = new Node(val);
            _size++;
            return true;
        }
        if (thisNode._value == val)
        {
            return false;
        }
        else if (thisNode._value > val)
            return _insertHelper(thisNode._left, val);
        else if (thisNode._value < val)
            return _insertHelper(thisNode._right, val);
    }


    template<typename T>
    bool BinarySearchTree<T>::insert(const T& val)
    {
        return _insertHelper(_root, val);

    }

    template<typename T>
    const size_t BinarySearchTree<T>::size() const
    {
        return _size;
    }

    template<typename T>
    bool BinarySearchTree<T>::remove(const T&) 
    {
        return true;
    }
    
    template<typename T>
    bool BinarySearchTree<T>::search(const T& val)
    {
        Node* thisNode = _root;
        while (thisNode != nullptr)
        {
            if (thisNode._value == val)
                return true;
            else if (thisNode._value > val)
                thisNode = thisNode._left;
            else if (thisNode._value < val)
                thisNode = thisNode._right;
        }
        return false;
    }

    template<typename T>
    const std::vector<T> BinarySearchTree<T>::traverse(const T&)
    {
        std::vector<T> ans;
        Node* thisNode = _root;
        while (thisNode != nullptr)
        {
            ans.push_back(thisNode.value);
            if (thisNode._value == val)
                return ans;
            else if (thisNode._value > val)
                thisNode = thisNode._left;
            else if (thisNode._value < val)
                thisNode = thisNode._right;
        }
        return std::vector<T>();
    }
}