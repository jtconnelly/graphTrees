#include <iostream>
#include <vector>
#ifdef TEST_GRAPHS
#include "graph.h"
#endif;

void separator()
{
    std::cout << std::endl << std::string(20, '-') << std::endl;
}

typedef bool(*testFPtr)();

int main(int argc, char** argv)
{
    std::vector<testFPtr> functions;
#ifdef TEST_GRAPHS

#endif
    bool pass = true;
    for (auto& func : functions)
    {
        pass &= func();
        separator();
    }
    std::cout << "Overall Test Pass: " << pass << std::endl;
    return 0;
}