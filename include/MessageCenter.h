#ifndef MESSAGECENTER_H_INCLUDED
#define MESSAGECENTER_H_INCLUDED

#include <string>
#include <vector>
#include <map>

class MessageCenter {

	public:
	
		addObserver(std::string message, void (*function)(void));
		notify(std::string message, std::vector<int> args);	//	figure out better args system
		
	private:
	
		std::map<std::string, std::vector<void *(*)(void *)>> messages;	//	"void *(*)(void *)" is the gross ass function pointer bullcrap
		typedef std::map<std::string, std::vector<void *(*)(void *)>>::iterator i_messages;
		
};

#endif // MESSAGECENTER_H_INCLUDED