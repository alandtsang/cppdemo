# gRPC cpp demo

## Prepare
### Install grpc
```bash
$ git clone -b $(curl -L https://grpc.io/release) https://github.com/grpc/grpc
$ cd grpc
$ git submodule update --init
$ make && sudo make install
```
### Install protobuf
```bash
$ cd third_party/protobuf
$ ./configure
$ make && sudo make install
```
## Build
```
cd grpcdemo
mkdir build
cd build
cmake ..
./bin/greeter_server
./bin/greeter_client
```
