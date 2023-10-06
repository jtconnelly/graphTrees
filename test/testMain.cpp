#include <iostream>
#ifdef TEST_TREES
#include "bst.h"

bool testBST()
{
    Boots::BinarySearchTree<int> bst;
    int arr[] = {17, 3, 76, 80, 24, 18, 30, 83, 36, 6};
    for (auto val : arr)
    {
        bst.insert(val);
    }
    std::cout << std::boolalpha;
    std::cout << bst << std::endl;
    std::cout << "Search for 99 (Should fail): " << bst.search(99) << std::endl;
    std::cout << "Search for 17 (Should pass): " << bst.search(17) << std::endl;
    std::cout << "Traverse for 99 (Should fail): ";
    auto vec = bst.traverse(99);
    if (vec.empty())
        std::cout << "[] (empty vec)" << std::endl;
    else
    {
        std::cout << "[ ";
        for (auto it : vec)
        {
            std::cout << it << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "Search for 17 (Should pass): "; 
    vec = bst.traverse(17);
    if (vec.empty())
        std::cout << "[] (empty vec)" << std::endl;
    else
    {
        std::cout << "[ ";
        for (auto it : vec)
        {
            std::cout << it << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "Removing 99 (should return false)" << bst.remove(99) << std::endl;
    std::cout << "Removing 17 (should return true)" << bst.remove(17) << std::endl;
    std::cout << bst << std::endl;
    std::cout << "Removing 80 (should return true)" << bst.remove(80) << std::endl;
    std::cout << bst << std::endl;
    std::cout << "Removing 36 (should return true)" << bst.remove(36) << std::endl;
    std::cout << bst << std::endl;
    return true;
}
#endif

#ifdef TEST_GRAPHS
#include "graph.h"
#endif;

int main(int argc, char** argv)
{
#ifdef TEST_TREES
    testBST();
#endif
#ifdef TEST_GRAPHS

#endif
    return 0;
}