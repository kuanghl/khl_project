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