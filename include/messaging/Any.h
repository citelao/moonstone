#ifndef ANY_H
#define ANY_H

#include <iostream>
#include <typeinfo>

// inspired by Boost's any
// http://www.boost.org/doc/libs/1_55_0/doc/html/boost/any.html
class Any {
    public:
        // Empty constructor
        Any()
            : _type(&typeid(void)), _data(NULL) {};
    
        // Copy constructor
        Any(const Any &other)
            : _type(other.type()) {
//                const void* test = other.data<const void *>();
                _data = 0;
            };
    
        // Constructor based on templated type T; accepts all types.
        template<typename T> Any(const T &other)
            : _type(&typeid(T)), _data(other) {};
    
        // Casting
        template<typename T> operator T () const;
    
        // Info-getting
        const std::type_info *type() const;
        template<typename T> T data() const;
    
        ~Any();
    
    protected:
        const std::type_info *_type;
        const void *_data;
    
};

#endif // ANY_H