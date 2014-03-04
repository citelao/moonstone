#include <iostream>
#include <string>

#include "Any.h"

template<typename T> Any::operator T () const {
    if (typeid(T) != *this->type()) {
        throw std::bad_alloc();
    }
}

const std::type_info *Any::type() const {
    return this->_type;
}

template<typename T> T Any::data() const {
    return this->_data;
}

Any::~Any() {
    // TODO who is responsible for garbage collection?
//    std::cerr << "Unimplemented; who is responsible for garbage collecting my void pointer?" << std::endl;
}