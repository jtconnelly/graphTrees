#include <iostream>
#ifdef TEST_TREES
#include "bst.h"
#include "bTree.h"

bool testBST()
{
    std::cout << "TESTING BST..." << std::endl;
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
    std::cout << "Search for 83 (Should pass): " << bst.search(83) << std::endl;
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
    std::cout << "Search for 83 (Should pass): "; 
    vec = bst.traverse(83);
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

    std::cout << "Testing PASSED" << std::endl;
    return true;
}

bool testBTree()
{
    std::cout << "TESTING BTree..." << std::endl;
    Boots::BTree<int> tree(5);
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    tree.insert(18);
    tree.insert(50);
    tree.insert(16);
    tree.insert(40);
    tree.insert(80);
    tree.insert(90);
    tree.insert(95);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(100);
    tree.insert(130);
    tree.insert(180);
    tree.insert(120);
    tree.insert(160);
    tree.insert(65);
    tree.insert(240);

    std::cout << std::boolalpha;
    std::cout << tree.traverse() << std::endl;
    std::cout << "Search For 20 (should pass): " << tree.search(20) << std::endl;
    std::cout << "Search For 70 (should fail): " << tree.search(70) << std::endl;

    std::cout << "Removing 10 (should pass): " << tree.remove(10) << std::endl;
    std::cout << "Removing 70 (should fail): " << tree.remove(70) << std::endl;
    std::cout << tree.traverse() << std::endl;

    std::cout << "Testing PASSED" << std::endl;
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
    std::cout << std::endl << std::string(20, '-') << std::endl;
    testBTree();
#endif
#ifdef TEST_GRAPHS

#endif
    return 0;
}