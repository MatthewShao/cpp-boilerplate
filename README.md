# cpp-boilerplate
A C++ boilerplate with gtest and coverage support

## Usage
```bash
mkdir build
cd build
cmake ..
```
## Unit test
```bash
make test
../bin/test
```

## Coverage test
```bash
make coverage
```
Coverage report generated in `build/test/coverage/test/index.html`

## Release
```bash
mkdir Release
cd Release
cmake -DCMAKE_BUILD_TYPE=Release ..
make main
```

## Debug
```bash
mkdir Debug
cd Debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
make main
```