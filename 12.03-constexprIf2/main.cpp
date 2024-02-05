// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstdio>
#include <type_traits>

static void linux_api_call()
{
  puts("linux");
}

void mac_api_call() {}

void some_other_api_call() {}

template<class...>
inline constexpr bool always_false_v = false;

enum class OS { Linux, Mac, Windows, native = Mac };

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

/* First instantiated from: insights.cpp:57 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
void OSDependentStuff<void>()
{
  if constexpr(OS::native == OS::Linux) {
  } else /* constexpr */ {
    if(OS::native == OS::Mac) {
      mac_api_call();
    } else {
      some_other_api_call();
    }
  }
}
#endif

int main()
{
  OSDependentStuff<void>();
}