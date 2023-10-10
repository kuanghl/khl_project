#include "c_cpptest.h"
#include "stdio.h"

int add_simple(int i, int j){
    printf("%s input i %d j %d\n", __func__, i, j);
    return (i+j);
}

tErrorCode_t add_int_pointer(int i, int j, int* result){
    if(i == j){
        printf("%s input i == j Error1\n", __func__);
        return Error1;
    }
    *result = i + j;
    printf("%s input i != j\n", __func__);
    return Success;
}