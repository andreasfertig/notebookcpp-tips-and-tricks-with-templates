// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


#include <type_traits>

template<typename T, bool enable = true>
class Sample
{
public:
  int DisableThisMethodOnRequest() { return 42; }
};

int main()
{
  Sample<int, false> sample{};
}