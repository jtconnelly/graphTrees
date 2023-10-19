#pragma once
#include <array>

namespace Boots
{
    template <typename T, int SIZE>
    class BTree
    {
    public:

    private:

        struct Node
        {
            T _value;
            std::array<Node*, SIZE> children;
            size_t _sz = 0;
        };
    };
}