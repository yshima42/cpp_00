#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span {
 public:
  Span(const unsigned int N);
  virtual ~Span();
  Span(Span const &other);
  Span &operator=(Span const &other);

  // getters
  unsigned getSize() const;
  unsigned getNumItems() const;
  const std::vector<int> &getItems() const;

  // adding number to each vector
  void addNumber(const int num);

  template< typename Iterator >
  void addNumber(Iterator it, Iterator last);

  // calculators
  int shortestSpan() const;
  int longestSpan() const;

 private:
  unsigned int _size;
  unsigned int _num_items;
  std::vector<int> _items;

  // did not use the following functions
  Span();
};

template< typename Iterator >
void Span::addNumber(Iterator it, Iterator last)
{
  for (; it != last; ++it) {
    this->addNumber(*it);
  }
}

#endif
