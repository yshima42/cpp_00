#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template < typename T>
class MutantStack : public std::stack<T> {
 public:
  MutantStack(){}
  virtual ~MutantStack(){}
  MutantStack(MutantStack const &other) { *this = other; }
  MutantStack &operator=(MutantStack const &other) {
    if (this != &other) {
      this->c = other.c;
    }
    return *this;
  }

  typedef typename std::stack<T>::container_type::iterator iterator;
  typedef typename std::stack<T>::container_type::const_iterator const_iterator;
  typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
  typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }
  const_iterator begin() const { return this->c.cbegin(); }
  const_iterator end() const { return this->c.cend(); }
  reverse_iterator rbegin() { return this->c.rbegin(); }
  reverse_iterator rend() { return this->c.rend(); }
  const_reverse_iterator rbegin() const { return this->c.crbegin(); }
  const_reverse_iterator rend() const { return this->c.crend(); }
};

#endif

