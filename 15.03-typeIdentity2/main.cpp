// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


#include <vector>

template<typename T>
struct type_identity
{
  using type = T;
};

template<typename T>
using type_identity_t =
  typename type_identity<T>::type;

template<typename T>
void manipulate(std::vector<T>,
                type_identity_t<T>,
                int idx);

template<typename T>
void manipulate(std::vector<T>,
                type_identity_t<T>,
                int idx)
{
}

int main()
{
  std::vector<int> v{};

  manipulate(v, 5, 0);
}