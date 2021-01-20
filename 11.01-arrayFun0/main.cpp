// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


void Fun(char array[20])
{
  // does something with the array data
  // plus expects array of size 20
}

int main()
{
  char a[5]{};

  Fun(a);
}