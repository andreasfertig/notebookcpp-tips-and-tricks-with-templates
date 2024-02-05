// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstdio>
#include <type_traits>

template<typename T>
class Wrapper {
public:
  Wrapper(const Wrapper&)
    requires std::is_copy_constructible_v<T>
  = default;
  Wrapper() = default;
};

class NonCopyable {
public:
  NonCopyable(const NonCopyable&)           = delete;
  NonCopyable operator=(const NonCopyable&) = delete;
};

template<typename T>
concept Test =
  requires(Wrapper<T> w) { Wrapper<T>{w}; };

int main()
{
  Wrapper<NonCopyable> w1{};

  struct Object {};

  Wrapper<Object> w3{};
  Wrapper<Object> w4{w3};

  static_assert(not Test<NonCopyable>);
}