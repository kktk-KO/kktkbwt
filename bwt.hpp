#include <vector>
#include <iostream>
#include <algorithm>

namespace kktkbwt {

template <class Iterator>
void print (Iterator first, Iterator last)
{
  for (; first < last; ++first) {
    if (*first == '\0') {
      std::cout << '$';
    } else {
      std::cout << *first;
    }
  }
  std::cout << std::endl;
}

template <class Iterator>
struct default_lexically_lesser
{
  bool operator() (Iterator left, Iterator right) noexcept
  {
    if (*left == '\0' && *right == '\0') { return false; }
    if (*left == '\0' && *right != '\0') { return true; }
    if (*left != '\0' && *right == '\0') { return false; }
    return *left < *right || (*left == *right && (*this)(++left, ++right));
  }
};

template <
  class RandomAccessIterator1,
  class RandomAccessIterator2,
  class OutputIterator,
  class DifferenceType,
  class LexicallyLesser = default_lexically_lesser<RandomAccessIterator1>
>
void bwt (RandomAccessIterator1 in, RandomAccessIterator2 aux, OutputIterator out, DifferenceType size)
{
  for (DifferenceType i = 0; i < size; ++i) { aux[i] = i; }

  std::sort(aux, aux + size, [&] (DifferenceType l, DifferenceType r) {
    return LexicallyLesser()(in + l, in + r); }
  );
  
  for (DifferenceType i = 0; i < size; ++i) { out[i] = in[(aux[i] + size - 1) % size]; }
}

}

