// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


#include <cstdio>

short int max(short int a, short int b)
{
  return (a > b) ? a : b;
}

int main()
{
  short int          a = 1;
  unsigned short int b = 65'530;

  printf("max: %d\n", max(a, b));
}