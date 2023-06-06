#include <stdlib.h>
#include <cstdio>
#include<string.h>

extern "C" void printf_green(const char *s)
{
    printf("\033[0m\033[1;32m%s\033[0m", s);
}

extern "C" void getOsInfo()  
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
  
extern "C" void getCpuInfo()  
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
  
extern "C" void getMemoryInfo()  
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

extern "C" int getLoglevel(){
    int res = 0;
    #ifdef LOG_LEVEL
        res = LOG_LEVEL;
    #else
        res = 3;
    #endif 
    return res;
}

extern "C" char *getPlatform(){
    char *string;
    #ifdef RPP_SIM_RT
        string = "RPP_SIM_RT";
    #else
        #ifdef RPP_FPGA
            string = "RPP_FPGA";
        #else
            #ifdef RPP_ASIC
                string = "RPP_ASIC";
            #else
                string = "RPP_ASIC";
            #endif 
        #endif    
    #endif 
    return string;
}

extern "C" char *getMpulib(){
    char *string;
    #ifdef USE_MPU_LIB
        string = "on";
    #else
        string = "off";
    #endif 
    return string;
}

extern "C" char *getMps(){
    char *string;
    #ifdef RPP_MPS_EN
        if(RPP_MPS_EN == 1)
            string = "on";
        else
            string = "off";
    #else
        string = "off";
    #endif 
    return string;   
}

extern "C" char *getDaemon(){
    char *string;
    #ifdef RPP_DAEMON_EN
        if(RPP_DAEMON_EN == 1)
            string = "on";
        else
            string = "off";
    #else
        string = "off";
    #endif   
}

extern "C" void printf_RppConfig(){
    printf("loglevel = %d.\n", getLoglevel());
    printf("platform = %s.\n", getPlatform());
    printf("mpulib = %s.\n", getMpulib());
    printf("mps = %s.\n", getMps());
    printf("daemon = %s.\n", getDaemon());
    printf("\n\n");
}

int main(void){
    printf_green("--rpp config---------------------------------\n");  
    printf_RppConfig(); 

    printf_green("--os information-----------------------------\n");  
    getOsInfo();  

    printf_green("--cpu infomation-----------------------------\n");  
    getCpuInfo();  
  
    printf_green("--memory information-------------------------\n");  
    getMemoryInfo();  
  
    return 0;
}
