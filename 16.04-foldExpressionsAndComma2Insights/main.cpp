// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <vector>

template<typename T, typename... Args>
void push_back(std::vector<T>& v, Args&&... args)
{
  static_assert(sizeof...(args) > 0);
  v.resize(v.size() + sizeof...(args));

  (v.push_back(args), ...);
}

/* First instantiated from: insights.cpp:16 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
void push_back<int, int, int, int, int>(
  std::vector<int, std::allocator<int>>& v,
  int&&                                  __args1,
  int&&                                  __args2,
  int&&                                  __args3,
  int&&                                  __args4)
{
  /* PASSED: static_assert(4 > 0); */
  v.resize(v.size() + 4);
  v.push_back(__args1),
    (v.push_back(__args2),
     (v.push_back(__args3), v.push_back(__args4)));
}
#endif

int main()
{
  std::vector<int> v =
    std::vector<int, std::allocator<int>>{};
  push_back(v, 2, 3, 4, 5);
}