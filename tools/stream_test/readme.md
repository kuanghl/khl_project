- 带宽测试
```
export OMP_NUM_THREADS=8
gcc -O3  -mtune=native -march=native -fopenmp -DN=200000000 -DNTIMES=100 stream.c -o stream
# 多线程
gcc -O -mtune=native -march=native -mcmodel=large -fopenmp -DSTREAM_ARRAY_SIZE=100000000 -DNTIMES=30 -DOFFSET=4096 stream.c -o stream
# 单线程
gcc -O -mtune=native -march=native -mcmodel=large -DSTREAM_ARRAY_SIZE=100000000  -DNTIME=30 -DOFFSET=4096  stream.c -o stream
```