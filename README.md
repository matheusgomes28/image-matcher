# Image Matcher App

[![CircleCI](https://dl.circleci.com/status-badge/img/gh/matheusgomes28/image-matcher/tree/main.svg?style=shield)](https://dl.circleci.com/status-badge/redirect/gh/matheusgomes28/image-matcher/tree/main)

This is an image matching app created with OpenCV.
It simply just matches input templates in the
given images.

The purpose of this application was to learn CircleCI,
so this is a farily simple application for now.

## Requirements

If you want to build this locally, you will need
to install the following requirements:

 - A Compiler (tested with `gcc` and `msvc` so far)
 - `cmake`
 - `conan` < 2.0 (and hence `python3` & `pip`)

## Building

Firstly, you will need to install the `conan` 
dependencies with the following command

```sh
conan install . \
      --install-folder conan \
      --build=missing -scompiler=gcc \
      -scompiler.version=9 \
      -scompiler.libcxx=libstdc++11 \ #only if on Linux
      -c tools.system.package_manager:mode=install
```

Then, you can use the following `cmake` calls to
configure, build and install everything here.

```sh
cmake . --preset <PRESET_NAME>
cmake --build --preset <PRESET_NAME>
cmake --install build/<PRESET_NAME>
```

Where `<PRESET_NAME>` is the preset that best suits
your setup. Take a look at the `CMakePresets.json` to
see all available presets.