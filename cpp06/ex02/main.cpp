#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include "color.hpp"

Base* generate(void) {
  std::srand(std::time(NULL));
  switch (rand() % 3) {
    case 0:
      return new A();
      break;
    case 1:
      return new B();
      break;
    case 2:
      return new C();
      break;
    default:
      throw std::exception();
  }
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p)) {
    std::cout << "A" << std::endl;
    return;
  } else if (dynamic_cast<B*>(p)) {
    std::cout << "B" << std::endl;
    return;
  } else if (dynamic_cast<C*>(p)) {
    std::cout << "C" << std::endl;
    return;
  } else {
    std::cout << "Base" << std::endl;
  }
}

void identify(Base& p) {
  try {
    (void)dynamic_cast<A&>(p);
    std::cout << "A" << std::endl;
  } catch (const std::bad_cast& bc) {
    try {
      (void)dynamic_cast<B&>(p);
      std::cout << "B" << std::endl;
    } catch (const std::bad_cast& bc) {
      try {
        (void)dynamic_cast<C&>(p);
        { std::cout << "C" << std::endl; }
      } catch (const std::exception& bc) {
        std::cout << "Base" << std::endl;
      }
    }
  }
}

int main() {
  try {
    Base* random_class = generate();
    Base base_class;
    std::cout << YELLOW << "---Random class---" << RESET << std::endl;
    identify(random_class);
    identify(*random_class);
    std::cout << YELLOW << "---Base class(not A, B, or C)---" << RESET
              << std::endl;
    identify(&base_class);
    identify(base_class);
    delete random_class;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}
