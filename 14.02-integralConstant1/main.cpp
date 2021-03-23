// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <type_traits>
template<auto I>
using integral_constant =
  std::integral_constant<decltype(I), I>;

auto x17 = integral_constant<2>();

static_assert(integral_constant<3>::value == 3);
int main() {}
