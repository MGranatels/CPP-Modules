#include <iostream>
#include <limits>

int main() {
    std::cout << "Max float: " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "Max double: " << std::numeric_limits<double>::max() << std::endl;
    return 0;
}
