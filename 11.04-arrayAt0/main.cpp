// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cassert>
#include <cstddef>

template<typename T, size_t N>
auto at(const T (&ar)[N], size_t pos)
{
  assert(pos < N);

  return ar[pos];
}

int main()
{
  char buffer[4]{'a', 'b', 'c', 'd'};

  assert(at(buffer, 2) == 'c');
}