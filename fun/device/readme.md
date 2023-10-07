# linux 驱动
- uxx为用户态驱动程序,`./user/uxx`
- kxx为内核态驱动程序,`./kernel/kxx`

### 独立linux驱动项目,内核态kernel--用户态user
#### kernel
- `cd fun/device/kernel/kdemo`
- `bash ./load_kernel_module.sh load`编译加载kernel驱动
- `bash ./load_kernel_module.sh  unload`清除编译卸载kernel驱动
#### user
- `cd build`
- 执行`cmake ..`&&`make -j16`&&`sudo make install`&&`./funbin/uioctl`

### 整个项目linux驱动开发测试,内核态kernel--用户态user
#### kernel
- `cd build`
- `cmake ..`&&`make -j16`&&`sudo make install`编译安装
- `cd build/fun/device/kernel/kxx`
- `sh ./load_module.sh load`加载驱动
- `sh ./load_module.sh unload`卸载驱动
#### user
- `cd build/funbin`
- `./uxx`
