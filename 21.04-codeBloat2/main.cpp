// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstdio>

int Open()
{
  return 1;
}
void Close(int) {}

void write(int, const char*, size_t) {}

template<typename T>
class span {
public:
  constexpr span() = default;

  constexpr span(const span&) = default;
  constexpr span& operator=(const span&) = default;

  template<size_t Extent>
  constexpr span(T (&arr)[Extent])
  : data_(arr)
  , length(Extent)
  {}

  constexpr size_t size() const { return length; }
  constexpr T*     data() const { return data_; }
  constexpr bool   empty() const
  {
    return nullptr != data();
  }

  constexpr T* begin() const { return data(); }
  constexpr T* end() const { return data() + size(); }

private:
  T*     data_;
  size_t length;
};

void Write(span<const char> data)
{
  const int fd = Open();

  // do some additional things

  write(fd, data.data(), data.size());

  Close(fd);
}

int main()
{
  char buffer[10]{};
  Write(buffer);

  char buffer2[20]{};
  Write(buffer2);
}