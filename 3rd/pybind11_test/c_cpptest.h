#ifndef __C_CPPTEST_H__
#define __C_CPPTEST_H__

#ifdef __cplusplus
extern "C" {
#endif

enum tErrorCode
{   
    Success = 0,
    Error1 = 1,
    Error2 = 2,
    Error_Res = 0xffff
};
typedef enum tErrorCode tErrorCode_t;

extern int add_simple(int i, int j);

extern tErrorCode_t add_int_pointer(int i, int j, int* result);

#ifdef __cplusplus
}
#endif

#endif // !__C_CPPTEST_H__