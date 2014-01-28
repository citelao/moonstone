#include <string>
#include <vector>
#include <map>

#include "MessageCenter.h"

MessageCenter::addObserver(std::string message, void (*function)(void)) {

	if(i_messages.find(message) == i_messages.end()) {	//	string already a key
		messages[message].push_back(void (*function)(void));	//	is this the right syntax for function pointer asignments? I doubt it.
	}
	else {
		messages[message] = new std::vector<void *(*)(void *)>;
		messages[message].push_back(void (*function)(void));
	}
	
}

MessageCenter::notify(std::string message, std::vector<int> args) {

	for(int i=0; i < messages[message].length(); i++) {
		messages[message][i]();
	}

}