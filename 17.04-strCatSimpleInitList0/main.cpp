// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <initializer_list>
#include <vector>

template<typename T, typename... Args>
void push_back(std::vector<T>& v, Args&&... args)
{
  std::initializer_list<T>{
    ((void)v.push_back(std::forward<Args>(args)),
     0)...};
}

int main()
{
  std::vector<int> v{};

  push_back(v, 2, 3, 4, 5);
}