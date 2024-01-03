- [notcurse](https://github.com/dankamongmen/notcurses.git) 
- [build](https://github.com/dankamongmen/notcurses/blob/master/INSTALL.md)

```sh
sudo apt-get install build-essential cmake doctest-dev libavdevice-dev libdeflate-dev libgpm-dev libncurses-dev libqrcodegen-dev libswscale-dev libunistring-dev pandoc pkg-config
sudo apt-get install libtinfo-dev
sudo apt-get install libncursesw5-dev

# 查找包位置
sudo updatedb
locate tinfo.pc
locate ncursesw.pc

# 例如
/snap/jupyter/6/lib/pkgconfig/ncursesw.pc
/usr/lib/x86_64-linux-gnu/pkgconfig/ncursesw.pc

# 配置pkgconfig查找包路径(将/usr/lib/x86_64-linux-gnu/pkgconfig/替换为你安装包的位置)
pkg-config --variable pc_path pkg-config
export PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/usr/lib/x86_64-linux-gnu/pkgconfig/

# 检验是否能找到
pkg-config --modversion tinfo
pkg-config --modversion ncursesw

# 编译
mkdir build
cd build
cmake ..
make -j16
```