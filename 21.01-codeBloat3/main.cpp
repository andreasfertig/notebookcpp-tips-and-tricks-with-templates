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

void Write(const char* data, const size_t len)
{
  printf("f: %s\n", __PRETTY_FUNCTION__);

  const int fd = Open();

  // do some additional things

  write(fd, data, len);

  Close(fd);
}

int main()
{
  char buffer[10]{/* some data */};
  Write(buffer, sizeof(buffer));

  char buffer2[20]{/* some other data */};
  Write(buffer2, sizeof(buffer2));
}