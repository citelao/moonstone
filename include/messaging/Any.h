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
            : _type(other.type()), _data(other.data<void const *>()) {};
    
        // Constructor based on templated type T; accepts all types.
        template<typename T> Any(const T &other)
            : _type(&typeid(T)), _data((void *)other) {};
    
        // Casting
        template<typename T> operator T () const {
            if (typeid(T) != *this->type()) {
                throw std::bad_alloc();
            }
            
            return this->data<T>();
        }
    
        // Info-getting
        const std::type_info *type() const;
        template<typename T> T data() const {
            return (T)this->_data;
        }
    
        // Printing
//        void print(std::ostream& os) const;
//        {
//            os << "Any (" << _type << "), '" << _data <<  "'" << std::endl;
//        }
    
        ~Any();
    
    protected:
        const std::type_info *_type;
        const void *_data;
    
};

// Any cout-ing.
//std::ostream& operator<<(std::ostream& os, const Any& object)
//{
//    object.print(os);
//    return os;
//}

#endif // ANY_H