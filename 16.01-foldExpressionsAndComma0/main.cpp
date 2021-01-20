// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


#include <vector>

template<typename T, typename Arg, typename... Args>
void push_back(std::vector<T>& v,
               Arg&&           arg,
               Args&&... args)
{
  if constexpr(0 < sizeof...(args)) {
    v.push_back(std::forward<Arg>(arg));

    push_back(v, args...);
  }
}

int main()
{
  std::vector<int> v{};

  push_back(v, 2, 3, 4, 5);
}