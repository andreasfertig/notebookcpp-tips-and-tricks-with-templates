// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

template<typename T>
struct something {
  using type = T;
};

template<typename T>
using something_t = typename something<T>::type;

int main()
{
  something_t<int> x = 2;
}