#include "conan2pocotest.h"
#include <vector>
#include <string>

int main() {
    conan2pocotest();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    conan2pocotest_print_vector(vec);
}
