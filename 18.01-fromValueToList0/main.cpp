// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstddef>

using Object = int;

// #include "compare.cpp"

template<typename T, size_t N>
constexpr bool Compare(const T (&a)[N],
                       const T (&b)[N])
{
  return false;
}

int main()
{
  Object a[5]{};
  Object b[5]{};

  // random fill a and b

  bool isSame = Compare(a, b);
}