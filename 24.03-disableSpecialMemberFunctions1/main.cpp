// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstdio>
#include <type_traits>

template<bool IsCopyable>
struct test_if_copyable {};

template<>
struct test_if_copyable<false> {
  test_if_copyable(const test_if_copyable&) = delete;
  test_if_copyable
  operator=(const test_if_copyable&) = delete;

  test_if_copyable() = default;
};

template<typename T>
class Wrapper : private test_if_copyable<
                  std::is_copy_constructible_v<T>> {
public:
};

class NonCopyable {
public:
  NonCopyable(const NonCopyable&)           = delete;
  NonCopyable operator=(const NonCopyable&) = delete;
};

class Object {};

int main()
{
  static_assert(not std::is_copy_constructible_v<
                Wrapper<NonCopyable>>);

  static_assert(
    std::is_copy_constructible_v<Wrapper<Object>>);
}