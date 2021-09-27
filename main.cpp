#include <iostream>
#include <sstream>
#include <string>
#include "set.hpp"

int main()
{
    set a, b;
    std::cin >> a;
    std::cin >> b;

    std::cout << a.size() << "\n"<< b.size() << "\n";
    std::cout << a.union_(b);
    std::cout << a.inter_(b);
    std::cout << a.dif_(b);
    std::cout << b.dif_(a);
    std::cout << a.interf().size() << "\n";
    std::cout << b.interf().size();
}