// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


#include <cstdio>
#include <list>
#include <vector>

template<template<class, class> class Container,
         class T,
         class Allocator = std::allocator<T>>
void Fun(const Container<T, Allocator>& c)
{
  for(const auto& e : c) {
    printf("%d\n", e);
  }
}

int main()
{
  std::vector<int> v{2, 3, 4};
  Fun(v);

  std::list<char> l{'a', 'b', 'c'};
  Fun(l);
}