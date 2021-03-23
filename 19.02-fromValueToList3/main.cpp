// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstddef>
#include <utility>

using Object = int;
template<typename T, size_t N>
constexpr bool Compare(const T (&a)[N],
                       const T (&b)[N])
{
  return [&]<size_t... I>(std::index_sequence<I...>)
  {
    return ((a[I] == b[I]) && ...);
  }
  (std::make_index_sequence<N>{});
}

int main()
{
  Object a[5]{};
  Object b[5]{};

  // random fill a and b

  bool isSame = Compare(a, b);
}