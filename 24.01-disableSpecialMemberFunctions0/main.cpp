// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstdio>
#include <type_traits>

template<typename T>
class Wrapper {
public:
  template<typename U,
           typename = std::enable_if_t<
             std::is_same_v<U, Wrapper> &&
             std::is_copy_constructible_v<T>>>
  Wrapper(const U&)
  {}

  Wrapper() = default;
};

class NonCopyable {
public:
  NonCopyable(const NonCopyable&)           = delete;
  NonCopyable operator=(const NonCopyable&) = delete;
};

int main()
{
  Wrapper<NonCopyable> w1{};

  Wrapper<NonCopyable> w2{w1};
}