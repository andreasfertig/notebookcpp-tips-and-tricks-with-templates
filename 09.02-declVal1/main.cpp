// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

template<typename T>
auto DeclValExample()
  -> decltype(T{}.SomeFunc(), void())
{
  // do something with the type
}

class DflCtr {
public:
  DflCtr() = default;

  bool SomeFunc() const { return false; }
};

int main()
{
  DeclValExample<DflCtr>();
}