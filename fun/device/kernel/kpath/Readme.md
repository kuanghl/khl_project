
### kernel get path

```sh
sudo insmod hello.ko module_path="$(pwd)" module_para=1,2,3,4,5,6,7,8,9,0,10
modinfo hello.ko
```