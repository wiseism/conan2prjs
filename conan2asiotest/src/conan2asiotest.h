#pragma once

#include <vector>
#include <string>


#ifdef _WIN32
  #define CONAN2ASIOTEST_EXPORT __declspec(dllexport)
#else
  #define CONAN2ASIOTEST_EXPORT
#endif

CONAN2ASIOTEST_EXPORT void conan2asiotest();
CONAN2ASIOTEST_EXPORT void conan2asiotest_print_vector(const std::vector<std::string> &strings);
