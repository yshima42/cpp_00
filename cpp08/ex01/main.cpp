#include <vector>

#include "color.hpp"
#include "span.hpp"

void testSubject() {
  try {
    std::cout << YELLOW << "---testSubject---" << RESET << std::endl;
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << std::endl;

  } catch (std::exception& e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }
}

void testError() {
  std::cout << YELLOW << "---testError---" << RESET << std::endl;

  try {
    Span sp = Span(5);
    sp.addNumber(5);
    std::cout << sp.shortestSpan() << std::endl;

  } catch (std::exception& e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }

  try {
    Span sp = Span(5);
    sp.addNumber(5);
    std::cout << sp.longestSpan() << std::endl;

  } catch (std::exception& e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }

  try {
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.addNumber(12);

  } catch (std::exception& e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }
  std::cout << std::endl;
}

void testIter() {
  std::cout << YELLOW << "---testIter---" << RESET << std::endl;
  try {
    int arr[5] = {2, 9, 3, 8, 4};
    std::vector<int> vec(arr, arr + 5);
    Span sp = Span(5);
    sp.addNumber(vec.begin(), vec.end());
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span sp2 = Span(5);
    sp2.addNumber(arr, arr + 5);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

  } catch (std::exception& e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }
  std::cout << std::endl;
}

void testIterError() {
  std::cout << YELLOW << "---testIterError---" << RESET << std::endl;
  try {
    int arr[6] = {2, 9, 3, 8, 4, 5};
    std::vector<int> vec(arr, arr + 6);
    Span sp = Span(5);
    sp.addNumber(vec.begin(), vec.end());
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

  } catch (std::exception& e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }
  std::cout << std::endl;
}

void testEdge() {
  std::cout << YELLOW << "---testEdge---" << RESET << std::endl;
  try {

    int arr[3] = {2147483647, 0, -2147483648};
    std::vector<int> vec(arr, arr + 3);
    Span sp = Span(3);
    sp.addNumber(vec.begin(), vec.end());
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

  } catch (std::exception& e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }
  std::cout << std::endl;
}

int main() {
  testSubject();
  testError();
  testIter();
  testEdge();
  testIterError();
}
