#include "iter.hpp"

void foo(int &a)
{
    std::cout << "I am foo()" << std::endl;
}
//can I put different types for T????????????
int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    iter(intArray, 5, foo);
}