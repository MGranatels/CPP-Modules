#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;

    vec.push_back(1);
    vec.push_back('a');
    vec.push_back(3);

    for (unsigned int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << std::endl;
    }

    return 0;
}