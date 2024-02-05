// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

template<typename T>
auto InsertTemplateArgs(const T& t)
  -> decltype(t.template_arguments(), void())
{
  InsertTemplateArgs(t.template_arguments());
}

template<typename T>
auto InsertTemplateArgs(const T& t)
  -> decltype(t.asArray(), void())
{
  InsertTemplateArgs(t.asArray());
}

#include <cstdio>

class Obj {
public:
  int x;
};

class Args {
public:
  Obj template_arguments() const
  {
    puts("template_arguments called");
    return {1};
  }
};

class Arr {
public:
  Obj asArray() const
  {
    puts("template_arguments called");
    return {2};
  }
};

void InsertTemplateArgs(const Obj& obj)
{
  printf("called with: %d\n", obj.x);
}

int main()
{
  Args ag{};
  Arr  ar{};

  InsertTemplateArgs(ag);
  InsertTemplateArgs(ar);
}