#include <algorithm>
#include "mutantstack.hpp"
#include "color.hpp"

template <typename T>
void printIter(T it, T ite) {
    while(it != ite) {
        std::cout << *it << std::endl;
        it++;
    }
}

void testSubject() {
  std::cout << YELLOW << "---testSubject---" << RESET << std::endl;
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);  //[...] mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
}

void testString()
{
    std::cout << YELLOW << "---testString---" << RESET << std::endl;
    MutantStack<std::string> s_stack;

    s_stack.push("hello");
    s_stack.push("world");
    s_stack.push("42tokyo");
    const MutantStack<std::string> cs_stack(s_stack);

    std::cout << CYAN << "<without const iterator>" << RESET << std::endl;
    MutantStack<std::string>::iterator it = s_stack.begin();
    MutantStack<std::string>::iterator ite = s_stack.end();
    printIter(it, ite);

    std::cout << CYAN << "<without const reverse_iterator>" << RESET << std::endl;
    MutantStack<std::string>::reverse_iterator r_it = s_stack.rbegin();
    MutantStack<std::string>::reverse_iterator r_ite = s_stack.rend();
    printIter(r_it, r_ite);

    std::cout << CYAN << "<with const iterator>" << RESET << std::endl;
    MutantStack<std::string>::const_iterator c_it = cs_stack.begin();
    MutantStack<std::string>::const_iterator c_ite = cs_stack.end();
    printIter(c_it, c_ite);

    std::cout << CYAN << "<without const reverse_iterator>" << RESET << std::endl;
    MutantStack<std::string>::const_reverse_iterator cr_it = cs_stack.rbegin();
    MutantStack<std::string>::const_reverse_iterator cr_ite = cs_stack.rend();
    printIter(cr_it, cr_ite);
    std::cout << std::endl;
}

void testFloat()
{
    std::cout << YELLOW << "---testFloat---" << RESET << std::endl;
    MutantStack<float> f_stack;
    f_stack.push(23.0f);
    f_stack.push(42.0f);
    f_stack.push(42.5f);
    f_stack.push(23.5f);
    const MutantStack<float> cf_stack(f_stack);

    std::cout << CYAN << "<without const iterator>" << RESET << std::endl;
    MutantStack<float>::iterator it = f_stack.begin();
    MutantStack<float>::iterator ite = f_stack.end();
    printIter(it, ite);

    std::cout << CYAN << "<without const reverse_iterator>" << RESET << std::endl;
    MutantStack<float>::reverse_iterator r_it = f_stack.rbegin();
    MutantStack<float>::reverse_iterator r_ite = f_stack.rend();
    printIter(r_it, r_ite);

    std::cout << CYAN << "<with const iterator>" << RESET << std::endl;
    MutantStack<float>::const_iterator c_it = cf_stack.begin();
    MutantStack<float>::const_iterator c_ite = cf_stack.end();
    printIter(c_it, c_ite);

    std::cout << CYAN << "<with const reverse_iterator>" << RESET << std::endl;
    MutantStack<float>::const_reverse_iterator rc_it = cf_stack.rbegin();
    MutantStack<float>::const_reverse_iterator rc_ite = cf_stack.rend();
    printIter(rc_it, rc_ite);

    std::cout << std::endl;
}

template< typename T >
class Cstack : public std::stack<T>
{
    public:
        std::deque<T> get_c() { return this->c; }
};

void praStack()
{
    Cstack<int> s;
    std::deque<int> d;
    s.push(1);
    s.push(4);
    s.push(3);
    s.push(19);
    d = s.get_c();
    std::cout << "at(2): " << d.at(2) << std::endl;
    std::cout << "size: "<< d.size() << std::endl;
    d.push_front(30);
    d.push_back(20);

    std::stack<int>::container_type::iterator it = d.begin();
    while (it != d.end())
    {
        std::cout << *it << std::endl;
        it++;
    }
}

int main() {
  testSubject();
  testString();
  testFloat();
  //praStack();
}
