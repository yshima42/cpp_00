#ifndef INCLUDE_GUARD_ITER_HPP
#define INCLUDE_GUARD_ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, size_t len, void (*f)(T &)) {
  if (!array || !f) return;
  for (size_t i = 0; i < len; i++) f(array[i]);
}

template <typename T>
void iter(const T *array, size_t len, void (*f)(const T &)) {
  if (!array || !f) return;
  for (size_t i = 0; i < len; i++) f(array[i]);
}

#endif
