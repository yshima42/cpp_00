#include "Array.hpp"
#include "color.hpp"

void testEmptyCopies() {
  std::cout << YELLOW << "--testEmptyCopies--" << RESET << std::endl;
  Array<int> arr_emp;
  Array<int> arr_emp_cpy(arr_emp);
  Array<int> arr_emp_cpy2 = arr_emp;

  std::cout << "size(arr_emp): " << arr_emp.size() << std::endl;
  std::cout << "size(arr_emp_cpy): " << arr_emp_cpy.size() << std::endl;
  std::cout << "size(arr_emp_cpy2): " << arr_emp_cpy2.size() << std::endl;
  std::cout << std::endl;
}

void testInt() {
  std::cout << YELLOW << "--testInt--" << RESET << std::endl;
  Array<int> arr_i(5);
  Array<int> arr_i_cpy(arr_i);
  Array<int> arr_i_cpy2 = arr_i;

  std::cout << "size(arr_emp): " << arr_i.size() << std::endl;
  std::cout << "size(arr_emp_cpy): " << arr_i_cpy.size() << std::endl;
  std::cout << "size(arr_emp_cpy2): " << arr_i_cpy2.size() << std::endl;

  for (unsigned int i = 0; i < arr_i.size(); i++) {
    arr_i[i] = i;
    arr_i_cpy[i] = i * 2;
    arr_i_cpy2[i] = i * 3;
  }
  std::cout << "arr_i = " << arr_i << std::endl;
  std::cout << "arr_i_cpy = " << arr_i_cpy << std::endl;
  std::cout << "arr_i_cpy2 = " << arr_i_cpy2 << std::endl;
  std::cout << std::endl;
}

void testString() {
  std::cout << YELLOW << "--testString--" << RESET << std::endl;
  Array<std::string> arr_s(5);
  arr_s[0] = "hello0";
  arr_s[1] = "hello1";
  arr_s[2] = "hello2";
  arr_s[3] = "hello3";
  arr_s[4] = "hello4";

  Array<std::string> arr_s_cpy(arr_s);
  Array<std::string> arr_s_cpy2 = arr_s;

  std::cout << "size(arr_emp): " << arr_s.size() << std::endl;
  std::cout << "size(arr_emp_cpy): " << arr_s_cpy.size() << std::endl;
  std::cout << "size(arr_emp_cpy2): " << arr_s_cpy2.size() << std::endl;

  std::cout << "arr_s = " << arr_s << std::endl;
  std::cout << "arr_s_cpy = " << arr_s_cpy << std::endl;
  std::cout << "arr_s_cpy2 = " << arr_s_cpy2 << std::endl;
  std::cout << std::endl;
}

int main() {
  try {
    testEmptyCopies();
    testInt();
    testString();

  } catch (std::exception& e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }
}
