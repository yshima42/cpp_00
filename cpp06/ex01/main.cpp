#include <iostream>

#include "Data.hpp"

int main() { 
    Data data1("yshima1", 5);
    Data data2;

    std::cout << data1 << std::endl;
    std::cout << data2 << std::endl;

    uintptr_t save_data = serialize(&data1);
    Data *raw_data = deserialize(save_data);

    std::cout << *raw_data << std::endl;
    
}
