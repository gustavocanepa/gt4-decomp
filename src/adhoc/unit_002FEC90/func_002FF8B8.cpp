typedef int s32;
typedef unsigned char u8;

extern "C" u8 HIO__read8(void *arg0);

extern "C" s32 func_002FF8B8(s32 arg0, u8 *arg1) {
    s32 s1 = arg0;
    *arg1 = HIO__read8((void *)s1);
    return s1;
}
