#include <stdlib.h>
#include <stdio.h>

/*
重置颜色属性:\033[0m
设置颜色属性:\033[1;34;36m%s
重置颜色属性:\033[0m
设置颜色属性代码编号:1;34;36(格式控制;前景色;背景色)
*/
void printf_red(const char *s)
{
    printf("\033[0m\033[1;31m%s\033[0m", s);
}

void printf_green(const char *s)
{
    printf("\033[0m\033[1;32m%s\033[0m", s);
}

void printf_yellow(const char *s)
{
    printf("\033[0m\033[1;33m%s\033[0m", s);
}

void printf_blue(const char *s)
{
    printf("\033[0m\033[1;35m%s\033[0m", s);
}

void printf_pink(const char *s)
{
    printf("\033[0m\033[1;35m%s\033[0m", s);
}

void printf_cyan(const char *s)
{
    printf("\033[0m\033[1;36m%s\033[0m", s);
}

void getOsInfo()  
{  
    FILE *fp = fopen("/proc/version", "r");    
    if(NULL == fp)     
        printf("failed to open version\n");     
    char szTest[65536] = {0};    
    while(!feof(fp))    
    {    
        memset(szTest, 0, sizeof(szTest));    
        fgets(szTest, sizeof(szTest) - 1, fp); // leave out \n  
        printf("%s", szTest);    
    }
    printf("\n\n");    
    fclose(fp);   
}  
  
void getCpuInfo()  
{  
    FILE *fp = fopen("/proc/cpuinfo", "r");    
    if(NULL == fp)     
        printf("failed to open cpuinfo\n");     
    char szTest[65536] = {0};     
    // read file line by line   
    while(!feof(fp))    
    {    
        memset(szTest, 0, sizeof(szTest));    
        fgets(szTest, sizeof(szTest) - 1, fp); // leave out \n  
        printf("%s", szTest);    
    } 
    printf("\n\n");   
    fclose(fp);   
}  
  
void getMemoryInfo()  
{  
    FILE *fp = fopen("/proc/meminfo", "r");    
    if(NULL == fp)     
        printf("failed to open meminfo\n");     
    char szTest[65536] = {0};    
    while(!feof(fp))    
    {    
        memset(szTest, 0, sizeof(szTest));    
        fgets(szTest, sizeof(szTest) - 1, fp);   
        printf("%s", szTest);    
    }   
    printf("\n\n"); 
    fclose(fp);   
} 

void getRppConfig(){
    #ifdef LOG_LEVEL
        printf("loglevel = %d.\n", LOG_LEVEL);
    #else
        printf("loglevel = defult(3).\n");
    #endif 

    #ifdef RPP_SIM_RT
        printf("platform = RPP_SIM_RT.\n");
    #else
        #ifdef RPP_FPGA
            printf("platform = RPP_FPGA.\n");
        #else
            #ifdef RPP_ASIC
                printf("platform = RPP_ASIC.\n");
            #else
                printf("platform = RPP_ASIC.\n");
            #endif 
        #endif    
    #endif 
    
    #ifdef USE_MPU_LIB
        printf("mpulib = on.\n");
    #else
        printf("mpulib = off.\n");
    #endif 
    
    #ifdef RPP_MPS_EN
        if(RPP_MPS_EN == 1)
            printf("mps = on.\n");
        else
            printf("mps = off.\n");
    #else
        printf("mps = off.\n");
    #endif 

    #ifdef RPP_DAEMON_EN
        if(RPP_DAEMON_EN == 1)
            printf("daemon = on.\n");
        else
            printf("daemon = off.\n");
    #else
        printf("daemon = off.\n");
    #endif 
    printf("\n\n");
}

int main(void){
    printf_green("===rpp config start===\n");  
    getRppConfig(); 

    printf_green("===os information start===\n");  
    getOsInfo();  

    printf_green("===cpu infomation start===\n");  
    getCpuInfo();  
  
    printf_green("===memory information start===\n");  
    getMemoryInfo();  
  
    return 0;
}