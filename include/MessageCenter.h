#ifndef MESSAGECENTER_H
#define MESSAGECENTER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "messaging/Any.h"

// typedef a responder method
// this is a void method that accepts a vector of objects (called "Any"s) sent by the caller
typedef void(*responder)(std::vector<Any>);

class MessageCenter {
    public:
        void registerObserver(std::string event, responder observer); // TODO throw error on nonregistered event
        bool registerEvent(std::string event);
    
        bool notify(std::string event, std::vector<Any> params); // TODO throw error on nonregistered event
    protected:
        std::map<std::string, std::vector<responder> > registeredResponders;
        std::vector<std::string> registeredEvents;
};

#endif // MESSAGECENTER_H