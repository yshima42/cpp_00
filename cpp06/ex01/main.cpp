#include <iostream>

#include "Data.hpp"
#include "color.hpp"

int main() {
  Data data1("yshima", 5);

  uintptr_t save_data = serialize(&data1);
  Data *raw_data = deserialize(save_data);

  std::cout << YELLOW << "---Pointer data---" << RESET << std::endl;
  std::cout << "data adress: " << &data1 << std::endl;
  std::cout << "after serialize adress: " << &save_data << std::endl;
  std::cout << "after deserialize adress: " << raw_data << std::endl;

  std::cout << std::endl;

  std::cout << YELLOW << "---Data size---" << RESET << std::endl;
  std::cout << "data size: " << sizeof(data1) << std::endl;
  std::cout << "after serialize data size: " << sizeof(save_data) << std::endl;
  std::cout << "after deserialize data size: " << sizeof(*raw_data)
            << std::endl;

  std::cout << std::endl;

  std::cout << YELLOW << "---Variable data---" << RESET << std::endl;
  std::cout << GREEN << "< before serialize >\n" << RESET << data1 << std::endl;
  std::cout << GREEN << "< after serialize and deserialize >\n" << RESET
            << *raw_data << std::endl;

  std::cout << std::endl;
}

//void detect_leak(void) __attribute__((destructor));

//void detect_leak(void) { system("leaks -q a.out"); }
