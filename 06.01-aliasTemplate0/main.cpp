// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

template<typename T>
struct something {
  using type = T;
};

int main()
{
  typename something<int>::type x = 2;
}