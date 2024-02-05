// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <vector>

template<typename T, typename Arg, typename... Args>
void push_back(std::vector<T>& v,
               Arg&&           val,
               Args&&... vals)
{
  v.push_back(std::forward<Arg>(val));

  if constexpr(0 < sizeof...(vals)) {
    push_back(v, std::forward<Arg>(vals)...);
  }
}

int main()
{
  std::vector<int> v{};

  push_back(v, 2, 3, 4, 5);
}