// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstddef>

template<typename T, size_t N>
constexpr auto size(const T (&ar)[N])
{
  return N;
}

int main()
{
  char buffer[4]{};

  static_assert(size(buffer) == 4);
}