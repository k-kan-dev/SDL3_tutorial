# SDL3_tutorial


## Concept
This code was based on YouTube Tutorial written in ref.<br>
Thanks a lot, Sonar System, the author of the movie.<br>
but the code in this tutorial movie was written based on SDL2. so I created same one using SDL3.<br>

## Environment
※ YOU SHOULD CONFIRM YOUR ENVIRONMENT.
- SDL3( SDL3-devel-3.2.4-mingw )
- Windows11 (64bit)
- VSCode as ide
- g++
```powershell
PS C:~\SDL3_tutorial> g++ --version
g++.exe (x86_64-win32-seh-rev0, Built by MinGW-Builds project) 13.2.0
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

## Requirements
1. download [SDL3](https://github.com/libsdl-org/SDL/releases)
    1. download `SDL3-devel-3.2.4-mingw.tar.gz`
    1. unpack and change dir name of `X86-64-MINGW32` into `src`
    1. move `src` to `./`; the top of this repository
    1. and move `./src/bin/SDL3.dll` to `./`
    1. see. the below "Directory-Structure"

1. install "make" command (<u>see.</u> [Make for Windows](https://gnuwin32.sourceforge.net/packages/make.htm))
    1. download `Complete package, except sopurces`
    1. and install the command along to the software

## Directory-Structure
- tree /f
```powershell
PS C:~\SDL3_tutorial> tree /f
C:.
│  .gitignore
│  Makefile
│  README.md
│  SDL3.dll
│  tutorial.cpp
│
├─output
│      tutorial.exe
│
└─src
    ├─bin
    ├─include
    │  └─SDL3
    │          SDL.h
    │          SDL_assert.h
    │              ~~~
    │          SDL_vulkan.h
    │
    ├─lib
    │  │  libSDL3.dll.a
    │  │  libSDL3_test.a
    │  │
    │  ├─cmake
    │  │  └─SDL3
    │  │          SDL3Config.cmake
    │  │          SDL3ConfigVersion.cmake
    │  │          SDL3headersTargets.cmake
    │  │          SDL3sharedTargets-release.cmake
    │  │          SDL3sharedTargets.cmake
    │  │          SDL3testTargets-release.cmake
    │  │          SDL3testTargets.cmake
    │  │
    │  └─pkgconfig
    │          sdl3.pc
    │
    └─share
        └─licenses
            └─SDL3
                    LICENSE.txt
```
## How to compile and execute
```powershell
PS C:~\SDL3_tutorial> mkdir output
PS C:~\SDL3_tutorial> make
g++ -I src/include -L src/lib -o output/tutorial tutorial.cpp -lmingw32 -lSDL3 
PS C:~\SDL3_tutorial> .\output\tutorial.exe
```

## How to close
alt + F4 or ESC-key

## Ref.
- tutorial video (thanks a lot, Sonar System!)    
    - [SDL 2 Tutorial Windows and Visual Studio Code Setup | Visual Studio Code, Game Dev](https://www.youtube.com/watch?v=jUZZC9UXyFs)
    - [SDL 2 Tutorial Change Background Colour](https://www.youtube.com/watch?v=lJM56id5YCY)
    - [SDL 2 Tutorial Keyboard Events](https://www.youtube.com/watch?v=YfGYU7wWLo8)
    - [SDL 2 Tutorial Mouse Events](https://www.youtube.com/watch?v=4Gq-gnMyJa0)

- SDL3
    - [SDL3_wiki](https://wiki.libsdl.org/SDL3/FrontPage)
- SDL2
    - [SDL2_wiki](https://wiki.libsdl.org/SDL2/FrontPage)
- make command
    - [Make for Windows](https://gnuwin32.sourceforge.net/packages/make.htm)