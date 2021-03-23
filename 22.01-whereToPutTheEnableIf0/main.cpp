// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstdio>
#include <type_traits>

template<
  typename T,
  typename = std::enable_if_t<std::is_integral_v<T>>>
void increment(T& value)
{
  ++value;
}

int main()
{
  int x = 2;
  increment(x);

  printf("Increment int: %d\n", x);

  // Does not compile, due to our template restriction
  // to integers
  //  float f = 3.14;
  //  increment(f);
}