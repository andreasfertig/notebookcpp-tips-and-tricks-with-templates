// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


#include <cstddef>

template<typename T, size_t SIZE>
class MyArray
{
  T array[SIZE];
};

int main()
{
  MyArray<int, 4> a{};
}