// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstdio>
#include <type_traits>

static void linux_api_call()
{
  puts("linux");
}

extern void mac_api_call();

void some_other_api_call() {}

/*
template<class T>
struct always_false : std::false_type
{
};

template<typename T>
constexpr bool always_false_v = always_false<T>::value;
*/
/*
template<class...>
inline constexpr bool always_false_v()
{
  return false;
}
*/

template<class...>
inline constexpr bool always_false_v = false;

enum class OS { Linux, Mac, Windows, native = Linux };

template<typename T>
void OSDependentStuff()
{
  if constexpr(OS::native == OS::Linux) {
    // Linux specific code
    linux_api_call();

  } else if(OS::native == OS::Mac) {
    // OS X specific code
    mac_api_call();

  } else {
    some_other_api_call();
  }
}

int main()
{
  OSDependentStuff<void>();
}