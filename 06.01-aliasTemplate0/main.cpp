// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


template<typename T>
struct something
{
  using type = T;
};

int main()
{
  typename something<int>::type x = 2;
}