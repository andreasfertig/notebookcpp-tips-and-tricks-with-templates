// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstdio>

template<typename T>
auto InsertTemplateArgs(const T& t)
{
  InternalInsertTemplateArgs(t.template_arguments());
}

template<typename T>
auto InsertTemplateArgsAsArray(const T& t)
{
  InternalInsertTemplateArgs(t.asArray());
}

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

void InternalInsertTemplateArgs(const Obj& obj)
{
  printf("called with: %d\n", obj.x);
}

int main()
{
  Args ag{};
  Arr  ar{};

  InsertTemplateArgs(ag);
  InsertTemplateArgsAsArray(ar);
}