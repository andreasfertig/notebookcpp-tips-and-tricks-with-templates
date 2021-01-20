// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


// It looks like they backported void_t
//#define CPP11

#ifdef CPP11
namespace std {
  template<typename...>
  struct void_t_impl
  {
    using type = void;
  };

  template<typename... T>
  using void_t = typename void_t_impl<T...>::type;

}  // namespace std
#endif

#include <type_traits>

template<class, class = void>
struct has_fun : std::false_type
{
};

template<class T>
struct has_fun<
  T,
  std::void_t<decltype(std::declval<T>().Fun())>>
: std::true_type
{
};

class A
{
public:
  void Fun();
};

class B
{
};

static_assert(has_fun<A>::value, "A");
static_assert(not has_fun<B>::value, "B");
int main() {}
