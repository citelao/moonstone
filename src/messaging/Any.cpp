#include <iostream>
#include <string>

#include "Any.h"

const std::type_info *Any::type() const {
    return this->_type;
}

Any::~Any() {
    // TODO who is responsible for garbage collection?
//    std::cerr << "Unimplemented; who is responsible for garbage collecting my void pointer?" << std::endl;
}