// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


void Fun(char* array) {}

int main()
{
  char a[5] = {'\0', '\0', '\0', '\0', '\0'};
  Fun(a);
}