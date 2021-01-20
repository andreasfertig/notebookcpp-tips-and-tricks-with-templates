// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


#include <cstdio>
#include <type_traits>

template<typename T>
void increment(
  T& value,
  std::enable_if_t<std::is_integral_v<T>>* = nullptr)
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