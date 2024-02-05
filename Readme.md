# Companion Source Code for "Notebook C++ - Tips and Tricks with Templates" 3. Edition

[![Build Status](https://github.com/andreasfertig/notebookcpp-tips-and-tricks-with-templates/workflows/ci/badge.svg)](https://github.com/andreasfertig/notebookcpp-tips-and-tricks-with-templates/actions/) [![License](https://img.shields.io/badge/license-MIT-blue.svg)](/LICENSE.txt)

![Book cover](.artwork/cover.png)

## Code examples

This repository contains runnable source code examples from the 3. edition of [Notebook C++ - Tips and Tricks with Templates](https://andreasfertig.com/books/notebookcpp-tips-and-tricks-with-templates/), by [Andreas Fertig](https://andreasfertig.com).

### The layout of the examples

The examples are separated into different directories based on how they appear in the book.

### Running the examples

The examples are in a single `.cpp` file that can be easily executed in any IDE. There is also an `CMakeLists.txt` which can generate IDE projects or be used to compile the example in a terminal.
This repo contains a top-level `CMakeLists.txt`, which does build all the examples.

### Building the examples

You can select the compiler by setting the `CXX` environment variable.

```
mkdir notebookcpp-tips-and-tricks-with-templates
cd notebookcpp-tips-and-tricks-with-templates
git clone https://github.com/andreasfertig/notebookcpp-tips-and-tricks-with-templates
mkdir build
cd build
cmake ../
cmake --build . -j
```

After that, you find all the executables in `notebookcpp-tips-and-tricks-with-templates/build/bin`.

Some examples use the latest C++ standard, so you will need a modern compiler to compile them. The latest stable versions of GCC or [Clang](https://releases.llvm.org/) are recommended. The code is not tested but is also expected to work with MSVC.

## License

The source code is released under the [MIT License](/LICENSE.txt).
