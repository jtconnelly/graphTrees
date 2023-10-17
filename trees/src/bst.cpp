#include <bst.h>

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
        _root = tree._root;
    }
    

    template<typename T>
    BinarySearchTree<T>::BinarySearchTree(BinarySearchTree&& tree) 
    {
        _size = tree._size;
        _root = tree._root;

        delete &tree;
    }



    template<typename T>
    bool BinarySearchTree<T>::_insertHelper(Node* thisNode, Node* prevNode, const T& val)
    {
        if (thisNode == nullptr)
        {
            thisNode = new Node(val);
            if (prevNode == nullptr)
                _root = thisNode;
            else if (thisNode->_value < prevNode->_value)
            {
                prevNode->_left = thisNode;
            }
            else if (thisNode->_value > prevNode->_value)
            {
                prevNode->_right = thisNode;
            }
            _size++;
            return true;
        }
        if (thisNode->_value == val)
        {
            return false;
        }
        else if (thisNode->_value > val)
            return _insertHelper(thisNode->_left, thisNode, val);
        else if (thisNode->_value < val)
            return _insertHelper(thisNode->_right, thisNode, val);
    }


    template<typename T>
    std::vector<T> BinarySearchTree<T>::_flatten(const Node* node) const
    {
        if (node == nullptr)
        {
            return std::vector<T>();
        }
        std::vector<T> ans;
        auto left = _flatten(node->_left);
        ans.insert(ans.end(), left.begin(), left.end());
        ans.push_back(node->_value);
        auto right = _flatten(node->_right);
        ans.insert(ans.end(), right.begin(), right.end());
        return ans;
    }

    template<typename T>
    const std::vector<T> BinarySearchTree<T>::flatten() const
    {
        if (_size == 0)
        {
            return std::vector<T>();
        }
        std::vector<T> ans;
        ans.reserve(_size);
        auto left = _flatten(_root->_left);
        ans.insert(ans.end(), left.begin(), left.end());
        ans.push_back(_root->_value);
        auto right = _flatten(_root->_right);
        ans.insert(ans.end(), right.begin(), right.end());
        return ans;
    }

    template<typename T>
    bool BinarySearchTree<T>::insert(const T& val)
    {
        return _insertHelper(_root, nullptr, val);

    }

    template<typename T>
    const size_t BinarySearchTree<T>::size() const
    {
        return _size;
    }

    template<typename T>
    bool BinarySearchTree<T>::remove(const T& val) 
    {
        if (_root == nullptr)
        {
            return false;
        }
        if (_root->_value == val)
        {
            if (_root->_left == nullptr && _root->_right == nullptr)
            {
                _root = nullptr;
            }
            else if (_root->_left != nullptr && _root->_right != nullptr)
            {
                Node* thisNode = _root->_left;
                Node* thisParent = _root;
                while (thisNode->_right != nullptr)
                {
                    thisParent = thisNode;
                    thisNode = thisNode->_right;
                }
                thisParent->_right = thisNode->_left;
                thisNode->_left = _root->_left;
                thisNode->_right = _root->_right;
                _root = thisNode;

            }
            else if (_root->_left != nullptr)
            {
                _root = _root->_left;
            }
            else if (_root->_right != nullptr)
            {
                _root = _root->_right;
            }
            return true;
        }
        Node* thisNode = _root;
        Node* thisParent = nullptr;
        while (thisNode != nullptr && thisNode->_value != val)
        {
            thisParent = thisNode;
            if (val > thisNode->_value)
            {
                thisNode = thisNode->_right;
            }
            else if (val < thisNode->_value)
            {
                thisNode = thisNode->_left;
            }
        }
        if (thisNode == nullptr)
            return false;
        if (thisNode->_left == nullptr && thisNode->_right == nullptr)
        {
            if (thisParent->_right == thisNode)
                thisParent->_right = nullptr;
            else
                thisParent->_left = nullptr;
        }
        else if (thisNode->_left != nullptr && thisNode->_right != nullptr)
        {
            Node* newThis = thisNode->_left;
            Node* finalParent = thisNode;
            while (newThis->_right != nullptr)
            {
                finalParent = newThis;
                newThis = newThis->_right;
            }
            finalParent->_right = newThis->_left;
            newThis->_left = thisNode->_left;
            newThis->_right = thisNode->_right;
            if (thisParent->_right == thisNode)
                thisParent->_right = newThis;
            else
                thisParent->_left = newThis;
        }
        else if (thisNode->_left != nullptr)
        {
            if (thisParent->_right == thisNode)
                thisParent->_right = thisNode->_left;
            else
                thisParent->_left = thisNode->_left;
        }
        else if (thisNode->_right != nullptr)
        {
            if (thisParent->_right == thisNode)
                thisParent->_right = thisNode->_right;
            else
                thisParent->_left = thisNode->_right;
        }
        return true;
    }
    
    template<typename T>
    bool BinarySearchTree<T>::search(const T& val) const
    {
        Node* thisNode = _root;
        while (thisNode != nullptr)
        {
            if (thisNode->_value == val)
                return true;
            else if (thisNode->_value > val)
                thisNode = thisNode->_left;
            else if (thisNode->_value < val)
                thisNode = thisNode->_right;
        }
        return false;
    }

    template<typename T>
    const std::vector<T> BinarySearchTree<T>::traverse(const T& val) const
    {
        std::vector<T> ans;
        Node* thisNode = _root;
        while (thisNode != nullptr)
        {
            ans.push_back(thisNode->_value);
            if (thisNode->_value == val)
                return ans;
            else if (thisNode->_value > val)
                thisNode = thisNode->_left;
            else if (thisNode->_value < val)
                thisNode = thisNode->_right;
        }
        return std::vector<T>();
    }
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Boots::BinarySearchTree<T>& obj)
{

    os << "[";
    const std::vector<T> vec = obj.flatten();
    for (auto itr = vec.begin(); itr != vec.end(); itr++)
    {
        os << *itr;
        if (itr + 1 != vec.end())
            os << ", ";
    }
    os << "]";
    return os;
}

template class Boots::BinarySearchTree<int>;
template std::ostream& operator<<(std::ostream& os, const Boots::BinarySearchTree<int>& obj);