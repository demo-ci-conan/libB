
#include "libB/libB.h"

#include <iostream>
#include "libA/libA.h"
#include "libF/libF.h"

void hello_libB(int indent, const std::string& msg) {
    std::cout << std::string(indent, ' ') << "libB: " << msg << std::endl;
    hello_libA(indent+1, "called from libB");
    hello_libF(indent+1, "called from libB");
}