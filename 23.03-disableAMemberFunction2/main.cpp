// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <type_traits>

template<typename T, bool enable = true>
class Sample {
public:
  template<typename Dummy = int>
  std::enable_if_t<enable, Dummy>
  DisableThisMethodOnRequest()
  {
    return 42;
  }
};

int main()
{
  Sample<int, false> sample{};

  Sample<int, true> sample2{};

  sample2.DisableThisMethodOnRequest();
}