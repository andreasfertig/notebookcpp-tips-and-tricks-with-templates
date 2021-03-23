// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstdio>

template<typename T>
T max(T a, T b)
{
  return (a > b) ? a : b;
}

int main()
{
  short int          a = 1;
  unsigned short int b = 65'530;

  // printf("max: %d\n", max(a, b));
}