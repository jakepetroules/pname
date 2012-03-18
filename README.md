[pname](http://www.petroules.com)
=================

pname is a replacement for the [uname](https://en.wikipedia.org/wiki/Uname) program found in Unix operating systems, whose name stands for "Unix name". In contrast, pname stands for "platform name", indicating its more general approach.

The problem with uname is that its outputs are very inconsistent across different Unix operating systems. Some may not support the same options, some may provide a different type of information for a particular option than another operating system do, and in general it provides relatively little useful information, especially not in a nice human-readable format.

The purpose of pname is to provide an easy way for software developers writing scripts (mainly as part of build processes) to discover a lot of information the underlying operating system. The goal is to support a variety of Unix systems, be able to provide information on individual Linux distributions, and provide a native binary for Windows that also works for shell scripts run in MinGW.



Quick start
-----------

Clone the repo, `git clone git@github.com:petroules/pname.git`, or [download the latest release](https://github.com/downloads/petroules/pname/pname.exe).



Bug tracker
-----------

This project is still very much a work in progress, so if you've found a bug, please create an issue here on GitHub!

https://github.com/petroules/pname/issues



Known issues
------------

pname for Windows builds with 32-bit MSVC, 64-bit MSVC or MinGW (32-bit), however only the 32-bit MSVC binary runs correctly. The 64-bit MSVC build has been observed to crash, and the MinGW build has been observed to crash in certain situations, such as whether it's run from cmd.exe or the MinGW shell. We will seek to fix these problems but they are not a priority as they will probably not inconvenience anyone.



Developers
----------

We have included makefiles for convenience of building. For Windows, you should open the 32-bit Visual Studio command prompt to properly set environment variables.

### Windows

+ **build** - `nmake -f makefile.win32`
Compiles pname to exes.

+ **clean** - `nmake -f makefile.win32 clean`
Removes all files generated by the build.

+ **install** - `nmake -f makefile.win32 install`
Copies pname.exe and uname.exe to %WINDIR% (usually C:\Windows)

### Unix

+ **install** - `make`
Copies the pname shell script to /usr/bin



FAQ
---

**Q: Why is there both a pname.exe and uname.exe?**

A: If you will be using MinGW in a scripting environment, download uname.exe as the pname shell script references it - otherwise it will use the MinGW uname program which will not return desired results (fortunately the script will fail with an error to prevent silent malfunction). In either case, the files are binary identical so it does not matter which one you use.

**Q: What dependencies are there?**

A: None. The Windows binary has no dependencies other than a few system DLLs that ship with the operating system, and the Unix implementation is merely a Bourne shell script that should work on virtually any Unix operating system.



Authors
-------

**Jake Petroules**

+ http://twitter.com/jakepetroules
+ http://github.com/jakepetroules



Copyright and license
---------------------

Copyright (c) 2012 Petroules Corporation. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met: 

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer. 
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.