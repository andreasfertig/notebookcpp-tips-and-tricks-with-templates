// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


#include <array>
#include <cstdio>
#include <string>

template<typename T>
struct SomeClass
{
  using type = T;
};

template<typename T>
void Fun(const T& t)
{
  using SUB_TYPE = typename T::type;

  // do something with SUB_TYPE
  SUB_TYPE x{};
}

int main()
{
  SomeClass<int> sc{};

  Fun(sc);
}