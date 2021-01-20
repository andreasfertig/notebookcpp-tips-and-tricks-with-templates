// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


#include <vector>

void manipulate(std::vector<int>& v, int val, int pos)
{
}

int main()
{
  std::vector<int> v{};

  manipulate(v, 5, 0);
}