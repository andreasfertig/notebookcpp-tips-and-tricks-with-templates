// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


#include <cstdio>
#include <type_traits>

template<typename T, typename... Ts>
constexpr auto
min(const T& a, const T& b, const Ts&... ts)
{
  auto m = a < b ? a : b;

  if constexpr(sizeof...(ts) > 0) {
    auto cmp = [&](const auto& value) {
      if(value < m) {
        m = value;
      }
    };

    (..., cmp(ts));
  }

  return m;
}

static_assert(min(3, 2, 3, 4, 5) == 2);
static_assert(min(3, 2) == 2);

int main() {}