#include "MessageCenter.h"

#include <iostream>

bool MessageCenter::registerObserver(std::string event, responder a) {
    
    std::cout << "registering " << event << std::endl;
    (a)(std::vector<void*>());
    
    return false;
}

bool MessageCenter::notify(std::string event) {
    std::cout << "notify" << std::endl;
}