A dockerized REST "Hello World" written in C++.

The code uses [CPPRestSDK](https://github.com/Microsoft/cpprestsdk) and is partially based on [this sample](https://github.com/Pintulalm/Restweb).

# Installation

The sample currently only runs on macOS and via Docker.

## macOS

* Install XCode.
* `brew install git cmake boost`
* `./libs/build_dependencies.sh`

# Build & Run

* `cmake -DCMAKE_BUILD_TYPE=Release . && cmake --build .` - Replace _Release_ with _Debug_ for a build with debug symbols.
* `./crest <PORT>`

## Docker

* `docker-compose build && docker-compose up`
* Re-build the container after changing code: `docker-compose down && docker-compose build && docker-compose up`

The very first build will take several minutes as it e.g. builds a more recent version of CMake from source. Subsequent builds will only re-compile the code in `/app`.