// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


template<typename... Ts>
struct is
{
  // ...
};

template<typename... Ts>
is(Ts&&...) -> is<Ts&&...>;  // CTAD

int main()
{
  auto x = is{};
}