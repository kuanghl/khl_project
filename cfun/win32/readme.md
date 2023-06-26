- env:
```
sudo vim /etc/apt/sources.list
deb http://us.archive.ubuntu.com/ubuntu trusty main universe
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install mingw32
# i + TAB 输出i + TAB键查找编译器i586-mingw32msvc-gcc
```
- demo：test.c
  ```c
  #include <stdio.h>
  int main()
  {
  	printf("windows application\n");

      // 以_WIN32宏判断，以便Linux下也可以编译通过
  	#ifdef _WIN32
      system("pause");
      #endif

  	return 0;
  }
  ```
- 编译：
  ```
  i586-mingw32msvc-gcc test.c -o test.exe
  # 拷贝到windows执行
  ```