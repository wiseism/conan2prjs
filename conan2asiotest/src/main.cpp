#include "conan2asiotest.h"
#include <vector>
#include <string>

int main() {
    conan2asiotest();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    conan2asiotest_print_vector(vec);
}
