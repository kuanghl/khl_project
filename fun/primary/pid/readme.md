- 查看进程信息`cat /proc/pid/stat`
  ```{.line-numbers}
  2057501 (gdm-session-wor) S 1 2048762 2048762 0 -1 4194560 1021 2223 0 0 1 0 2 0 20 0 3 0 1357257 174768128 2139 18446744073709551615 1 1 0 0 0 0 0 4096 16896 0 0 0 17 3 0 0 0 0 0 0 0 0 0 0 0 0 0
  ```
  [linux官方参考](https://linux.die.net/man/5/proc)
- eg：
  - name_to_pid:
    - void printf_pid(char *pid_name)
    - int is_digit_dir(char *dirname)
    - void getpid_all(void)
    - int getpid_by_name(char *pid_name, pid_t *pid, uint8_t *pid_num)
    - void getname_by_pid(pid_t pid, char *pid_name)