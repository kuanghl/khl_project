FROM ubuntu:20.04

RUN apt-get update
RUN apt-get install sudo
RUN apt-get install -y build-essential bash 
COPY test_eg1 test_eg1
WORKDIR /test_eg1/shm_sem
RUN gcc -o memwriter memwriter.c -lrt -lpthread
RUN gcc -o memreader memreader.c -lrt -lpthread 
CMD /bin/bash
