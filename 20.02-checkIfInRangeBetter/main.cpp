// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstdio>
#include <type_traits>
#include <utility>

template<typename T>
struct remove_cvref {
  using type =
    std::remove_cv_t<std::remove_reference_t<T>>;
};

template<typename T>
using remove_cvref_t = typename remove_cvref<T>::type;

template<typename T, typename...>
struct first_type {
  using type = remove_cvref_t<T>;
};

template<typename T, typename... Ts>
struct are_same {
  static constexpr bool value = std::conjunction_v<
    std::is_same<remove_cvref_t<T>,
                 remove_cvref_t<Ts>>...>;
};

template<typename T, typename... Ts>
constexpr bool are_same_v = are_same<T, Ts...>::value;

template<typename... Ts>
struct is {
  // struct is
  using BaseType = typename first_type<Ts...>::type;

  static constexpr auto SIZE = sizeof...(Ts);

  static_assert(
    are_same_v<BaseType, Ts...>,
    "Only parameters of the same type are allowed.");

  const BaseType values[SIZE];

  constexpr is(Ts&&... vals)
  : values{std::forward<Ts>(vals)...}
  {}

  // #include "StructIsInRangeDeclaration.cpp"

  constexpr bool in_range(const BaseType& min,
                          const BaseType& max) const
  {
    return compare(
      min, max, std::make_index_sequence<SIZE>{});
  }

  template<std::size_t... I>
  constexpr bool
  compare(const BaseType& min,
          const BaseType& max,
          std::index_sequence<I...>) const
  {
    return (
      ((min <= values[I]) && (values[I] <= max)) &&
      ...);
  }

  template<std::size_t... I>
  constexpr bool
  compare_equal(const BaseType& value,
                std::index_sequence<I...>) const
  {
    return ((value == values[I]) && ...);
  }

  constexpr bool equal(const BaseType& value) const
  {
    return compare_equal(
      value, std::make_index_sequence<SIZE>{});
  }

  constexpr bool
  operator==(const BaseType& value) const
  {
    return equal(value);
  }

  friend constexpr bool operator==(const BaseType& lhs,
                                   const is&       rhs)
  {
    return rhs == lhs;
  }
};

template<typename... Ts>
is(Ts&&...) -> is<Ts&&...>;  // CTAD

int main()
{
  constexpr int x = 2;
  constexpr int y = 3;
  constexpr int z = 4;

  if(is{x, y, z}.in_range(2, 5)) {
    // ...
  }

  static_assert(is{x, y, z}.in_range(2, 5),
                "x,y,z not in range of 2,3");
  static_assert(not is{x, y, z}.in_range(3, 5),
                "x,y,z not in range of 2,3");
  static_assert(not is{x, y, z}.in_range(2, 3),
                "x,y,z not in range of 2,3");

  if((x == 0) && (y == 0) && (z == 0)) {
    // ...
  }

  if(is{x, y, z} == 0) {
    // ...
  }

  printf("in_range: %d\n",
         is{6, 2, 3, 4, 5}.in_range(1, 5));
  printf("in_range: %d\n",
         is{5, 2, 3, 4, 5}.in_range(1, 5));
  printf("in_range: %d\n",
         is{3, 2, 3, 4, 5}.in_range(1, 5));

  constexpr int a = 1;
  constexpr int b = 1;
  constexpr int c = 1;

  static_assert(is{a, b, c} == 1,
                "a,b,c are not all 1");
  static_assert(1 == is{a, b, c},
                "a,b,c are not all 1");

  static_assert(not(is{a, b, c} == 0),
                "a,b,c are not all 1");
  static_assert(not(0 == is{a, b, c}),
                "a,b,c are not all 1");
}