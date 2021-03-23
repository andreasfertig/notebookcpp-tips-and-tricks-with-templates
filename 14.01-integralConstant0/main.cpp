// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

template<class T, T val>
struct integral_constant {
  static constexpr T value = val;

  // ...
};

static_assert(integral_constant<int, 3>::value == 3);
int main() {}
