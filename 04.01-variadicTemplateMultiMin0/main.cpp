// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstdio>
#include <type_traits>

template<typename T,
         typename... Ts  // #A Variadic template
         >
constexpr auto
min(const T& a,
    const T& b,
    const Ts&... vals)  // #B Parameter pack
{
  const auto m = a < b ? a : b;
  if constexpr(sizeof...(vals)  // #C size of a pack
               > 0) {
    return min(m, vals...);     // #D Expand the pack
  }

  return m;
}

static_assert(min(3, 2, 3, 4, 5) == 2);
static_assert(min(3, 2) == 2);

int main() {}