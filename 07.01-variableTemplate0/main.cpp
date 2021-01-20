// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


template<typename T>
struct something
{
  using type = T;

  static const bool value = false;
};

int main()
{
  static_assert(not something<int>::value);
}