#pragma once

#include <vector>
#include <string>


#ifdef _WIN32
  #define CONAN2POCOTEST_EXPORT __declspec(dllexport)
#else
  #define CONAN2POCOTEST_EXPORT
#endif

CONAN2POCOTEST_EXPORT void conan2pocotest();
CONAN2POCOTEST_EXPORT void conan2pocotest_print_vector(const std::vector<std::string> &strings);
