#include "span.hpp"

#include <algorithm>
#include <stdexcept>
#include <vector>

Span::Span(const unsigned int N) : _size(N), _num_items(0) {}

Span::~Span() {}

Span::Span(Span const &other) { *this = other; }

Span &Span::operator=(Span const &other) {
  if (this != &other) {
    this->_size = other._size;
    this->_num_items = other._num_items;
    this->_items = other._items;
  }
  return *this;
}

unsigned Span::getSize() const { return _size; }

unsigned Span::getNumItems() const { return _num_items; }

const std::vector<int> &Span::getItems() const { return _items; }

void Span::addNumber(const int num) {
  if (_num_items < _size) {
    _items.push_back(num);
    ++_num_items;
  } else {
    throw std::length_error("Error: This object is full");
  }
}

long Span::longestSpan() const {
  if (_num_items < 2) {
    throw std::range_error("Error: longestSpan: Need more than 2 numbers");
  } else {
    std::vector<int>::const_iterator min =
        std::min_element(_items.begin(), _items.end());
    std::vector<int>::const_iterator max =
        std::max_element(_items.begin(), _items.end());
    return static_cast<long>(*max) - static_cast<long>(*min);
  }
}

long Span::shortestSpan() const {
  if (_num_items < 2) {
    throw std::range_error("Error: shortestSpan: Need more than 2 numbers");
  } else {
    long ret = LONG_MAX;
    std::vector<int> sort_items(_items);
    std::sort(sort_items.begin(), sort_items.end());
    for (std::vector<int>::const_iterator it = sort_items.begin();
         it < sort_items.end() - 1; it++) {
      long tmp = static_cast<long>(*(it + 1)) - static_cast<long>(*it);
      if (tmp < ret) {
        ret = tmp;
      }
    }
    return ret;
  }
}
