#include <iostream>
#include <utility>

#define F(x, y) std::make_pair(x + y, x)
#include "data.inc"
#undef F

#define F(x, y) std::make_pair(x ## y, #x)
#include "data.inc"
#undef F

int main() {
    auto a = 
        #include "data.inc"
        ;

    auto b = 
        #include "data.inc"
        ;

    std::cout << "First: " << a.first + b.first << std::endl;
    std::cout << "Second: " << a.second + 1 << ", " << b.second + 1 << std::endl;

    return 0;
}
