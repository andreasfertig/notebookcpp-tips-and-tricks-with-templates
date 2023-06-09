// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

template<class  // #A typename is fine as well
         T,
         template<typename>
         class Cont,  // #B Pre C++17 class was
                      // required
         typename U>
class Container {
  // #C Only typename
  using size_type = typename Cont<U>::size_type;

  // #D Requires typename
  typename Cont<U>::ptr_type* mData{};
};

template<typename T>
struct MyClass {
  using size_type = int;
  using ptr_type  = T;
};

Container<int, MyClass, char> cont{};
int main() {}
