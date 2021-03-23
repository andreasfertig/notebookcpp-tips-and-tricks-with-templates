// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <type_traits>

template<typename T, bool enable = true>
class Sample {
public:
  int DisableThisMethodOnRequest() { return 42; }
};

int main()
{
  Sample<int, false> sample{};
}