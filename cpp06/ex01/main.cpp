#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data d;
    d.value = 1337;

    uintptr_t raw = Serializer::serialize(&d);
    std::cout << "serialized pointer: " << raw << std::endl;

    Data* ptr2 = Serializer::deserialize(raw);
    std::cout << "Original ptr: \t" << &d << std::endl;
    std::cout << "Deserialized ptr: " << ptr2 << std::endl;

    if (&d == ptr2)
        std::cout << "Success: pointers match!\n";
    else
        std::cout << "Error: pointers differ!\n";
    return 0;
}
