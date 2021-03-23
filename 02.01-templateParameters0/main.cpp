// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstddef>

template<typename T, size_t SIZE>
class MyArray {
  T array[SIZE];
};

int main()
{
  MyArray<int, 4> a{};
}