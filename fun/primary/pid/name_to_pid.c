#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdint.h>

#if 1
/*
通过shell指令根据进程名称pid_name输出pid
*/
void printf_pid(char *pid_name){
	char cmd[256];
	memset(cmd, 0, 256);
	pid_t pid = getpid();
	sprintf(cmd, "ps -e | grep %s | awk '{print $1}'", pid_name);
	system(cmd);
}

//判断文件夹名称是否为全数字
int is_digit_dir(char *dirname){
    char *p = dirname;
    for(; *p; p++){
        if(!isdigit(*p)){
            return 0;
        }
    }
    return 1;
}
//获取全部进程信息
void getpid_all(void){
	DIR *procdir;
    FILE *fp;
    struct dirent *entry;
    char path[256]; //d_name + /proc + /stat
    unsigned long maj_faults;
    int pid_tmp;

    // Open /proc directory.
    procdir = opendir("/proc");
    if (!procdir) {
        printf("opendir failed.\n");
        return -1;
    }

    // Iterate through all files and folders of /proc.
    while ((entry = readdir(procdir))) {

        if(!is_digit_dir(entry->d_name)) continue;

        // Try to open /proc/<PID>/stat.
        snprintf(path, sizeof(path), "/proc/%s/stat", entry->d_name);
        fp = fopen(path, "r"); 

        // Get PID, process name and number of faults.
        fscanf(fp, "%d %s %*c %*d %*d %*d %*d %*d %*u %*lu %*lu %lu",
            &pid_tmp, &path, &maj_faults
        );
 
        // Pretty print.
        printf("%8d %-40s: %lu\n", pid_tmp, path, maj_faults);
        fclose(fp);   
    }
}
//根据进程名称查看某个进程是否存在(可能有同名进程)
int getpid_by_name(char *pid_name, pid_t *pid, uint8_t *pid_num){
	DIR *procdir;
    FILE *fp;
    struct dirent *entry;
    char path[256]; //d_name + /proc + /stat
    unsigned long maj_faults;
    char name_tmp[256];
    pid_t pid_tmp;

    // Open /proc directory.
    procdir = opendir("/proc");
    if (!procdir) {
        printf("opendir failed.\n");
        return -1;
    }

    // Iterate through all files and folders of /proc.
    while ((entry = readdir(procdir))) {

        if(!is_digit_dir(entry->d_name)) continue;

        // Try to open /proc/<PID>/stat.
        snprintf(path, sizeof(path), "/proc/%s/stat", entry->d_name);
        fp = fopen(path, "r"); 

        // Get PID, process name and number of faults.
        fscanf(fp, "%d %s %*c %*d %*d %*d %*d %*d %*u %*lu %*lu %lu",
            &pid_tmp, &path, &maj_faults
        );
 
        // get pid
        sprintf(name_tmp, "(%s)", pid_name);
        if(strcmp(path, name_tmp) == 0){
            pid[*pid_num] = pid_tmp;
            *pid_num = *pid_num + 1;
        }
        fclose(fp);   
    }

    if(*pid_num == 0){
        return -1;
    }
    return 0;
}
//根据pid获取进程名称
void getname_by_pid(pid_t pid, char *pid_name){
	DIR *procdir;
    FILE *fp;
    struct dirent *entry;
    char path[256]; //d_name + /proc + /stat
    unsigned long maj_faults;
    pid_t pid_tmp;

    // Open /proc directory.
    procdir = opendir("/proc");
    if (!procdir) {
        printf("opendir failed.\n");
        return -1;
    }

    // Iterate through all files and folders of /proc.
    while ((entry = readdir(procdir))) {

        if(!is_digit_dir(entry->d_name)) continue;

        // Try to open /proc/<PID>/stat.
        snprintf(path, sizeof(path), "/proc/%s/stat", entry->d_name);
        fp = fopen(path, "r"); 

        // Get PID, process name and number of faults.
        fscanf(fp, "%d %s %*c %*d %*d %*d %*d %*d %*u %*lu %*lu %lu",
            &pid_tmp, &path, &maj_faults
        );
 
        // get pidname
        if(pid_tmp == pid){
            strcpy(pid_name, path);
            fclose(fp);  
            return;
        }
        fclose(fp);   
    }
}
 
int main(int argc, char *argv[])
{
    int r;
    pid_t pid[256];
    uint8_t pid_num = 0;
    char pid_name[256];
    getpid_all();
    printf_pid("pid_test");
    r = getpid_by_name("gdm-session-wor", pid, &pid_num);
    if(r < 0){
        printf("pid is no exist.\n");
        return -1;
    }
    for(int i = 0; i < pid_num; i++){
        printf("pid = %d.\n", pid[i]);
    }

    pid[0] = getpid();
    getname_by_pid(pid[0], pid_name);
    printf("pid_name = %s.\n", pid_name);
	
	return 0;
}

#elif 0

// Helper function to check if a struct dirent from /proc is a PID folder.
int is_pid_folder(const struct dirent *entry) {
    const char *p;
 
    for (p = entry->d_name; *p; p++) {
        if (!isdigit(*p)) //非数字
            return 0;
    }
 
    return 1;
}
 
int main(void) {
    DIR *procdir;
    FILE *fp;
    struct dirent *entry;
    char path[256 + 5 + 5]; // d_name + /proc + /stat
    int pid;
    unsigned long maj_faults;
 
    // Open /proc directory.
    procdir = opendir("/proc");
    if (!procdir) {
        perror("opendir failed");
        return 1;
    }
 
    // Iterate through all files and folders of /proc.
    while ((entry = readdir(procdir))) {
        // Skip anything that is not a PID folder.
        if (!is_pid_folder(entry)) //非数字
            continue;
 
        // Try to open /proc/<PID>/stat.
        snprintf(path, sizeof(path), "/proc/%s/stat", entry->d_name);
        fp = fopen(path, "r");
 
        if (!fp) {
            perror(path);
            continue;
        }
 
        // Get PID, process name and number of faults.
        fscanf(fp, "%d %s %*c %*d %*d %*d %*d %*d %*u %*lu %*lu %lu",
            &pid, &path, &maj_faults
        );
 
        // Pretty print.
        printf("%5d %-20s: %lu\n", pid, path, maj_faults);
        fclose(fp);
    }
 
    return 0;
}
#endif