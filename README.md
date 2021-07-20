# ShakeScreen

## About

Very basic win32 app for "shaking" the screen, written in C using GDI.

The code migt be bad, sorry for that. If you have any corrections, let me know on my [Discord server](https://grial.tech/discord) (I'm grialion#4595)!

## Why did I create this?

I created this program and documentation, because I want to archive all the steps of creating/compiling Win32 apps on Linux.

Obviously you can compile it on Windows too, but I recommend using WSL for that. The instructions should work under an Ubuntu WSL.

## Okay, so how do I compile and test this?

1. You need to install MinGW-w64
   - Arch Linux
        ```sh
        $ sudo pacman -S mingw-w64-gcc
        ```
    - Debian
        ```sh
        $ sudo apt install gcc-mingw-w64-i686 # for Win32
        $ sudo apt install gcc-mingw-w64-x86-64 # for Win64
        ```

1. Compiling the source
    - Win32
        ```sh
        i686-w64-mingw32-gcc -std=c99 -g main.c -lgdi32 -s -Os -o shakescreen.exe
        ```
    - Win64
        ```sh
        x86_64-w64-mingw32-gcc -std=c99 -g main.c -lgdi32 -s -Os -o shakescreen.exe
        ```

1. Running it
   
   I recommend using VirtualBox for this type of testing (if you know how to set up properly a Windows XP on qemu/kvm, please let me know on discord).
   Just set up a Windows XP, install guest additions and enable drag and drop and test it after compiling it.
## Credit(s)
- [wipet](https://www.youtube.com/channel/UCWn5-ZertW64IBIjRchLJuA) for teaching me some of the methods used in the example code