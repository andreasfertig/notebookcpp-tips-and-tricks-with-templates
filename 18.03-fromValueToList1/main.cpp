// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


#include <cstddef>
#include <utility>

using Object = int;

namespace details {
  template<typename T, size_t N, size_t... I>
  constexpr bool Compare(const T (&a)[N],
                         const T (&b)[N],
                         std::index_sequence<I...>);
}

namespace details {
  template<typename T, size_t N, size_t... I>
  constexpr bool Compare(const T (&a)[N],
                         const T (&b)[N],
                         std::index_sequence<I...>)
  {
    return ((a[I] == b[I]) && ...);
  }
}  // namespace details

template<typename T, size_t N>
constexpr bool Compare(const T (&a)[N],
                       const T (&b)[N])
{
  return details::Compare(
    a, b, std::make_index_sequence<N>{});
}

int main()
{
  Object a[5]{};
  Object b[5]{};

  // random fill a and b

  bool isSame = Compare(a, b);
}