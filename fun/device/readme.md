# linux 驱动

## kernel层直接操控硬件设备寄存器及物理内存
- `cd fun/device/kernel`
- 执行`bash ./load_kernel_module.sh  unload`/`bash ./load_kernel_module.sh load`编译安装kernel驱动

## user层通过ioctl设备文件流命令控制驱动
- `cd build`
- 执行`cmake ..`&&`make -j16`&&`sudo make install`&&`./funbin/ioctl`