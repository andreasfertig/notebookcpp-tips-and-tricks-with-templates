// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <vector>

template<typename T, typename... Args>
void push_back(std::vector<T>& v, Args&&... vals)
{
  if constexpr(0 < sizeof...(vals)) {
    (v.push_back(std::forward<Args>(vals)), ...);
  }
}

int main()
{
  std::vector<int> v{};

  push_back(v, 2, 3, 4, 5);
}