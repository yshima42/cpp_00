#include "span.hpp"

Span::Span(const unsigned int N) : _N(N) {}

Span::~Span() {}

Span::Span(Span const &other) { *this = other; }

Span &Span::operator=(Span const &other) {
  if (this != &other) {
    this->_N = other._N;
    this->_items = other._items;
  }
  return *this;
}

void Span::addNumber(const int num) {
  if (_items.size() >= _N) {
    throw std::length_error("Error: This object is full");
  } else {
    _items.push_back(num);
  }
}

unsigned int Span::longestSpan() const {
  if (_items.size() < 2) {
    throw std::range_error("Error: longestSpan: Need more than 2 numbers");
  } else {
    std::vector<int>::const_iterator min =
        std::min_element(_items.begin(), _items.end());
    std::vector<int>::const_iterator max =
        std::max_element(_items.begin(), _items.end());
    return *max - *min;
  }
}

unsigned int Span::shortestSpan() const {
  if (_items.size() < 2) {
    throw std::range_error("Error: shortestSpan: Need more than 2 numbers");
  } else {
    unsigned int ret = UINT_MAX;
    std::vector<int> sort_items(_items);
    std::sort(sort_items.begin(), sort_items.end());
    for (std::vector<int>::const_iterator it = sort_items.begin();
         it < sort_items.end() - 1; it++) {
      unsigned int tmp = *(it + 1) - *it;
      if (tmp < ret) {
        ret = tmp;
      }
    }
    return ret;
  }
}

const std::string Span::toString() const {
    std::stringstream sst;
    for (std::vector<int>::const_iterator p = _items.begin(); p != _items.end(); p++)
        sst << *p << " ";
    return sst.str();
}

std::ostream &operator<<(std::ostream &ost, const Span &rhs) {
    ost << rhs.toString(); 
    return ost;
}

