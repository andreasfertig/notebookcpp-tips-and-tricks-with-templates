// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

template<typename T>
struct something {
  using type = T;

  static const bool value = false;
};

int main()
{
  static_assert(not something<int>::value);
}