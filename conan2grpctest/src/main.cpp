#include "conan2grpctest.h"
#include <vector>
#include <string>

int main() {
    conan2grpctest();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    conan2grpctest_print_vector(vec);
}
