#pragma once

#include <vector>
#include <string>


#ifdef _WIN32
  #define CONAN2OPENCVTEST_EXPORT __declspec(dllexport)
#else
  #define CONAN2OPENCVTEST_EXPORT
#endif

CONAN2OPENCVTEST_EXPORT void conan2opencvtest();
CONAN2OPENCVTEST_EXPORT void conan2opencvtest_print_vector(const std::vector<std::string> &strings);
