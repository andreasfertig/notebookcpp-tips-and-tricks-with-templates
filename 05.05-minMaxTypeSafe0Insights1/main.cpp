// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


#include <cstdio>

short max(short a, short b)
{
  return (static_cast<int>(a) > static_cast<int>(b))
           ? a
           : b;
}

int main()
{
  short          a = static_cast<short>(1);
  unsigned short b =
    static_cast<unsigned short>(65530);
  printf(
    "max: %d\n",
    static_cast<int>(max(a, static_cast<short>(b))));
}