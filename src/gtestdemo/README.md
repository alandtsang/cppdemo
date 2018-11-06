# gtestdemo

cmake with googletest example.

## Install Googletest
```
$ sudo apt-get install libgtest-dev
```

## Download & Build
```
$ git clone https://github.com/alandtsang/cppdemo.git
$ cd cppdemo/src/gtestdemo
$ mkdir build && cd build
```
```
gtestdemo
├── CMakeLists.txt
├── include
│   └── sample.h
├── src
│   ├── CMakeLists.txt
│   ├── main.cpp
│   └── sample.cpp
└── test
    ├── CMakeLists.txt
    ├── main.cpp
    └── sample_test.cpp
```

### normal build
```
$ cmake ..
$ make
$ ./src/demo
Factorial(1)=1

```
### gtest build
```
$ cmake -Dtest=ON ..
$ make
$ ./test/sample_test 
Runtest...
[==========] Running 6 tests from 2 test cases.
[----------] Global test environment set-up.
[----------] 3 tests from FactorialTest
[ RUN      ] FactorialTest.Negative
[       OK ] FactorialTest.Negative (0 ms)
[ RUN      ] FactorialTest.Zero
[       OK ] FactorialTest.Zero (0 ms)
[ RUN      ] FactorialTest.Positive
[       OK ] FactorialTest.Positive (0 ms)
[----------] 3 tests from FactorialTest (0 ms total)

[----------] 3 tests from IsPrimeTest
[ RUN      ] IsPrimeTest.Negative
[       OK ] IsPrimeTest.Negative (0 ms)
[ RUN      ] IsPrimeTest.Trivial
[       OK ] IsPrimeTest.Trivial (0 ms)
[ RUN      ] IsPrimeTest.Positive
[       OK ] IsPrimeTest.Positive (0 ms)
[----------] 3 tests from IsPrimeTest (0 ms total)

[----------] Global test environment tear-down
[==========] 6 tests from 2 test cases ran. (0 ms total)
[  PASSED  ] 6 tests.
```

## Reference

[https://github.com/google/googletest/tree/master/googletest/samples](https://github.com/google/googletest/tree/master/googletest/samples/)
