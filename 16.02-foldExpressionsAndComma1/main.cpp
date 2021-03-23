// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <vector>

template<typename T, typename... Args>
void push_back(std::vector<T>& v, Args&&... args)
{
  if constexpr(0 < sizeof...(args)) {
    (v.push_back(args), ...);
  }
}

int main()
{
  std::vector<int> v{};

  push_back(v, 2, 3, 4, 5);
}