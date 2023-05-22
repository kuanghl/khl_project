# test_cpp_ci
Template C++ CI project

## Test frameworks

### env and compile/install.
```
sudo apt install lcov
cd doctest_fakeilt
mkdir build
cd build
cmake ..
make -j16
sudo make install
```

### doctest
* https://github.com/onqtam/doctest
* commit 4d8716f1efc1d14aa736ef52ee727bd4204f4c40
* 2.4.6

### FakeIt
* https://github.com/eranpeer/FakeIt
* commit 1576b26efca0a91361ff1974062c6da25ca944f6
* 2.0.7
