#pragma once

#include <vector>
#include <string>


#ifdef _WIN32
  #define CONAN2GRPCTEST_EXPORT __declspec(dllexport)
#else
  #define CONAN2GRPCTEST_EXPORT
#endif

CONAN2GRPCTEST_EXPORT void conan2grpctest();
CONAN2GRPCTEST_EXPORT void conan2grpctest_print_vector(const std::vector<std::string> &strings);
