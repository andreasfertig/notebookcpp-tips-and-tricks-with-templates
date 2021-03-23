// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstdio>

int Open()
{
  return 1;
}
void Close(int) {}

void write(int, const char*, size_t) {}

namespace details {
  void Write(const char* data, const size_t size)
  {
    const int fd = Open();

    // do some additional things

    write(fd, data, size);

    Close(fd);
  }
}  // namespace details

template<size_t N>
void Write(const char (&data)[N])
{
  details::Write(data, N);
}

int main()
{
  char buffer[10]{};
  Write(buffer);

  char buffer2[20]{};
  Write(buffer2);
}