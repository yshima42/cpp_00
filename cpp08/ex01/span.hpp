#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <climits>
#include <stdexcept>
#include <vector>
#include <sstream>

class Span {
 public:
  Span(const unsigned int N);
  virtual ~Span();
  Span(Span const &other);
  Span &operator=(Span const &other);

  // for operator <<
  const std::string toString() const;

  // adding number to each vector
  void addNumber(const int num);

  template <typename Iterator>
  void addNumber(Iterator it, Iterator last);

  // calculators
  unsigned int shortestSpan() const;
  unsigned int longestSpan() const;

 private:
  unsigned int _N;
  std::vector<int> _items;

  // did not use the following functions
  Span();
};

template <typename Iterator>
void Span::addNumber(Iterator it, Iterator last) {
  for (; it != last; ++it) {
    this->addNumber(*it);
  }
}

std::ostream &operator<<(std::ostream &ost, const Span &rhs);

#endif
