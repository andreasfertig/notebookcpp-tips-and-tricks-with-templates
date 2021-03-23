// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

template<typename T>
struct something {
  using type = T;

  static const bool value = false;
};

template<typename T>
constexpr bool something_v = something<T>::value;

int main()
{
  static_assert(not something_v<int>);
}