// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstdio>

#ifdef _MSC_VER
#  define __PRETTY_FUNCTION__ __FUNCSIG__
#endif

int Open()
{
  return 1;
}

void write(int, const char*, size_t) {}

void Close(int) {}

template<size_t N>
void Write(const char (&data)[N])
{
  printf("f: %s\n", __PRETTY_FUNCTION__);

  const int fd = Open();

  // do some additional things

  write(fd, data, N);

  Close(fd);
}

int main()
{
  char buffer[10]{};
  Write(buffer);

  char buffer2[20]{};
  Write(buffer2);
}