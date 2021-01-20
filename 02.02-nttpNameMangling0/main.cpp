// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


template<int I>
void fun()
{
}

int main()
{
  fun<23>();
  fun<39>();
}