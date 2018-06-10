#include "./utils.h"

unsigned int next_power2 (unsigned int const &l) {
  bool isPowerOf2 = !(l == 0) && !(l & (l - 1));
  if (isPowerOf2) {
    return l;
  }

  unsigned int p = l;
  p--;
  p |= p >> 1;
  p |= p >> 2;
  p |= p >> 4;
  p |= p >> 8;
  p |= p >> 16;
  p++;

  return p;
}