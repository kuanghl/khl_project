#include <stdio.h>
#include <stdlib.h>

#include <uv.h>
#include <log.h>

int main(int argc, char *argv[])
{
    uv_loop_t *loop = malloc(sizeof(uv_loop_t));
    uv_loop_init(loop);

    printf("hello world,now quitting.\n");
    uv_run(loop, UV_RUN_DEFAULT);

    //printf("loglevel = %d.\n", loglevel);

    log_trace("%s, this is codetest log, %s\n", __func__, "hello!");
    log_debug("%s, this is codetest log, %s\n", __func__, "hello!");
    log_info("%s, this is codetest log, %s\n", __func__, "hello!");
    log_warn("%s, this is codetest log, %s\n", __func__, "hello!");
    log_error("%s, this is codetest log, %s\n", __func__, "hello!");
    log_fatal("%s, this is codetest log, %s\n", __func__, "hello!");

    uv_loop_close(loop);
    free(loop);
    return 0;
}   
