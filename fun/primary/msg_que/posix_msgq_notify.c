#include <pthread.h>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <signal.h>
#include <string.h>

const char *mq_name = "/mq_test";


void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

static void tfunc(union sigval sv) {
    struct mq_attr attr;
    ssize_t nr;
    void *buf;
    mqd_t mqdes = *((mqd_t *) sv.sival_ptr);

    if (mq_getattr(mqdes, &attr) == -1) {
        handle_error("mq_getattr() error\n");
    }

    buf = malloc(attr.mq_msgsize);
    if (buf == NULL) {
        handle_error("malloc() error\n");
    }

    nr = mq_receive(mqdes, (char *) buf, attr.mq_msgsize, NULL);
    if (nr == -1) {
        handle_error("mq_receive() error\n");
    }

    printf("Read %zd bytes from MQ--%s\n", nr, buf);
    free(buf);
    exit(EXIT_SUCCESS);
}


int main() {
    mqd_t mqdes = mq_open(mq_name, O_CREAT | O_RDWR, 0777, NULL);
    if (mqdes < (mqd_t) 0) {
        handle_error("mq_open() error\n");
    }

    struct sigevent sev;
    bzero(&sev, sizeof(sev));
    sev.sigev_notify = SIGEV_THREAD;
    sev.sigev_notify_function = tfunc;
    sev.sigev_notify_attributes = NULL;
    sev.sigev_value.sival_ptr = &mqdes;  // 传递给tfunc的参数

    if (mq_notify(mqdes, &sev) == -1) {
        handle_error("mq_notify() error\n");
    }
    puts("sleep for 2 second...");
    sleep(2);

    const char *msg = "hello world kuanghl!";
    mq_send(mqdes, msg, strlen(msg), 1);
    pause();

    exit(EXIT_SUCCESS);
}
