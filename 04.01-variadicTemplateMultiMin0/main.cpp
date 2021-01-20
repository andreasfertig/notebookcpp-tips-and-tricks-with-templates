// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


#include <cstdio>
#include <type_traits>

template<typename T,
         typename... Ts  // #A Variadic template
         >
constexpr auto
min(const T& a,
    const T& b,
    const Ts&... ts)  // #B Parameter pack
{
  const auto m = a < b ? a : b;
  if constexpr(sizeof...(ts)  // #C size of a pack
               > 0) {
    return min(m, ts...);  // #D Expand the pack
  }

  return m;
}

static_assert(min(3, 2, 3, 4, 5) == 2);
static_assert(min(3, 2) == 2);

int main() {}