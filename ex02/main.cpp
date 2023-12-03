#include "Array.hpp"

int main()
{
    Array<int> intObj(3);
    Array<int> intObj1;

    std::cout << intObj[1] << std::endl;
    std::cout << intObj;
    std::cout << intObj1;
}