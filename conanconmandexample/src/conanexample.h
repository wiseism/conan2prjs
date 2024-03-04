#pragma once

#ifdef WIN32
  #define conanexample_EXPORT __declspec(dllexport)
#else
  #define conanexample_EXPORT
#endif

conanexample_EXPORT void conanexample();
