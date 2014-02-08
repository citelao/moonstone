#ifndef MESSAGECENTER_H
#define MESSAGECENTER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

// typedef a responder method
// this is a void method that accepts a void pointer vector of objects sent by the c
typedef void(*responder)(std::vector<void*>);

class MessageCenter {
    public:
        bool registerObserver(std::string event, responder a);
    
        bool notify(std::string event);
    
    protected:
        std::map<std::string, std::vector<responder> > registeredResponders;
};

#endif // MESSAGECENTER_H