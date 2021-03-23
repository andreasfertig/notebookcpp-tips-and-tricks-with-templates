// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

template<typename... Ts>
struct is {
  // ...
};

template<typename... Ts>
is(Ts&&...) -> is<Ts&&...>;  // CTAD

int main()
{
  auto x = is{};
}