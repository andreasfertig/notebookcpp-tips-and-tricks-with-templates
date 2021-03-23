// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

namespace std {
  template<typename T>
  T declval() noexcept
  {
    static_assert(sizeof(T) == 0, "Don't, just don't");
  }

}  // namespace std

template<typename T>
auto DeclValExample()
  -> decltype(std::declval<T>().SomeFunc(), void())
{
  // do something with the type
}

class DflCtr {
public:
  DflCtr() = default;

  bool SomeFunc() const { return false; }
};

class NoDflCtr {
public:
  NoDflCtr() = delete;
  NoDflCtr(int) {}

  bool SomeFunc() const { return false; }
};

int main()
{
  DeclValExample<DflCtr>();
  DeclValExample<NoDflCtr>();
}