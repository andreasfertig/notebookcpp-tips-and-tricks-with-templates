// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

template<typename T, bool enable = true>
class Sample {
public:
  int DisableThisMethodOnRequest()
    requires(enable)
  {
    return 42;
  }
};

int main()
{
  Sample<int, false> sample{};
}