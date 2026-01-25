#ifndef   SERIALIZER_HPP
# define  SERIALIZER_HPP

# include <cstdint>   // for uintptr_t
# include "Data.hpp"

class Serializer
{
private:
    Serializer();
    Serializer(const Serializer& other);
    ~Serializer();
    Serializer &operator=(const Serializer& other);
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif
