// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


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

class Obj
{
public:
  int x;
};

class Args
{
public:
  Obj template_arguments() const
  {
    printf("template_arguments called\n");
    return {1};
  }
};

class Arr
{
public:
  Obj asArray() const
  {
    printf("template_arguments called\n");
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