#include <iostream>
#include "classes/DateTime.h"
#include "tests.h"


int main() {
    DateTime a{2020, 11, 20};
    DateTime b{2020, 11, 22};
    auto x = a-b;

    std::cout << (b+x).Pretty();

    return 0;
}
