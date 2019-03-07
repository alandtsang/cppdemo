# cmake-staticlibrary

Suppose we have a mul() function that depends on add() function in the
static library libadd.a, and provide mul() function, then how to write cmake?

add.h
```c++
int add(int x, int y);
```

add.cpp
```c++
int add(int x, int y) {
  return x + y;
}
```

mul.h
```c++
int mul(int x, int y);
```

mul.cpp
```c++
int mul(int x, int y) {
  int result = 0;

  for (int i = 0; i < x; i++) {
    result = add(result, y);
  }
  return result;
}
```

main.cpp
```c++
int main() {
  std::cout << "mul(5, 6) = " << mul(5, 6) << "\n";
}
```

## Run
```
$ ./compile.sh
$ ./bin/test 
mul(5, 6) = 30
```
