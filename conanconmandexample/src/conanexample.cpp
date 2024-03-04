#include <iostream>
#include "conanexample.h"

void conanexample(){
    #ifdef NDEBUG
    std::cout << "conanexample/1.0: Hello World Release!" <<std::endl;
    #else
    std::cout << "conanexample/1.0: Hello World Debug!" <<std::endl;
    #endif
}
