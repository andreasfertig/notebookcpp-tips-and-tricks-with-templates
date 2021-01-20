// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


template<typename T>
auto DeclValExample()
{
  // do something with the type
}

class DflCtr
{
public:
  DflCtr() = default;

  bool SomeFunc() const { return false; }
};

int main()
{
  DeclValExample<DflCtr>();
}