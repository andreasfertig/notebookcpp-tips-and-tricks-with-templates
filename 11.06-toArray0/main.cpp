// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <array>
#include <cstddef>

namespace details {

  template<typename T, size_t N, size_t... I>
  constexpr std::array<std::remove_cv_t<T>, N>
    to_array(T (&arr)[N], std::index_sequence<I...>)
  {
    return {{arr[I]...}};
  }
}  // namespace details

template<typename T, size_t N>
constexpr auto to_array(const T (&ar)[N])
{
  return details::to_array(
    ar, std::make_index_sequence<N>());
}

int main()
{
  auto x = to_array("foo");

  static_assert(x.size() == 4);
}