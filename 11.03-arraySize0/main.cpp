// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


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