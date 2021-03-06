
# qt_cef_poc

Proof of concept of a very simplistic cross-platform Qt browser using Chromium Embedded Framework.

## Building

### Windows Prerequisites

Before running the build script on Windows, you must have the prerequisites:

* Latest Qt (5.x) installed w/ `qmake.exe` on the `PATH`
* Latest CMake installed w/ `cmake.exe` on the `PATH`
* Latest Python (2.x) installed w/ `python.exe` on the `PATH`
* Latest Go installed w/ `go.exe` on the `PATH`
* [MSVC 2015 Build Tools](http://landinghub.visualstudio.com/visual-cpp-build-tools) installed w/ the following
  executed to put 64-bit VC compiler on the `PATH`:
  `"C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" amd64`
* Latest [Windows 64-bit standard dist of CEF](http://opensource.spotify.com/cefbuilds/index.html#windows64_builds)
  extracted w/ `CEF_DIR` environment variable set to the base CEF extracted dir
* This repo cloned w/ the shell at the repo root

### Linux Prerequisites

Before running the build script on Windows, you must have the prerequisites:

* Latest Qt (5.x) installed w/ `qmake` on the `PATH`
* Latest CMake installed w/ `cmake` on the `PATH`
* Latest Python (2.x) installed w/ `python` on the `PATH`
* Latest Go installed w/ `go` on the `PATH`
* Latest GCC installed w/ `gcc` and `g++` on the `PATH`
* Latest Make installed w/ `make` on the `PATH`
* Latest [Linux 64-bit standard dist of CEF](http://opensource.spotify.com/cefbuilds/index.html#linux64_builds)
  extracted w/ `CEF_DIR` environment variable set to the base CEF extracted dir
* Latest GTK 2.x installed and on the library path
* This repo cloned w/ the shell at the repo root

### MacOS Prerequisites

(TODO)

### Running Build

The application uses the CEF C++ wrapper, which can be built via:

    go run build.go build-cef

Now the application can easily be run via:

    go run build.go run

That will run the `debug` version. For the `release` version, run:

    go run build.go run release

Internally, that just builds and runs the exe. To just build, call `build` instead. To package a deployment artifact
from a previously run build, `package` is used. For example, to package a `release` deployment artifact from a
previously run `release` build, run:

    go run build.go package release

Once complete, the package(s) will in `release/package` (e.g. qt_cef_poc.zip in Windows)

## TODO

* Fix focus issues between browser and URL bar on all platforms
* Move everything but the exe to a sub folder for cleaner deployment
  * For CEF, see [this](http://www.magpcss.org/ceforum/viewtopic.php?f=6&t=10296) post
  * May need to manually `LoadLibrary` and/or use
    [`SetDllDirectory`](https://msdn.microsoft.com/en-us/library/windows/desktop/ms686203(v=vs.85).aspx)
  * Consider instead cross platform shortcuts at the top level instead
  * Chrome does this, see their deployment dir and then look at their code on how they do it