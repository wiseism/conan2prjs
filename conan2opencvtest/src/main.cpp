#include "conan2opencvtest.h"
#include <vector>
#include <string>

int main() {
    conan2opencvtest();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    conan2opencvtest_print_vector(vec);
}
