// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


#include <vector>

template<typename T, typename... Args>
void push_back(std::vector<T>& v, Args&&... args)
{
  // What to do here?
}

int main()
{
  std::vector<int> v{};

  push_back(v, 2, 3, 4, 5);
}