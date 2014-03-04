#include "MessageCenter.h"

#include <iostream>

void MessageCenter::registerObserver(std::string event, responder observer) {
    
    std::cout << "registering " << event << std::endl;

    std::vector<responder> responders = registeredResponders[event];
    
    responders.push_back(observer);
    registeredResponders[event] = responders;
}

bool MessageCenter::notify(std::string event, std::vector<Any> params) {
    std::cout << "notifying for " << event << std::endl;
    
    for(auto observer : registeredResponders[event]) {
        (observer)(params);
    }
    
    return false;
}