typedef int s32;

extern "C" s32 func_0055F6A0(void *arg0, s32 arg1, s32 arg2);
extern char D_00667BC8[];

extern "C" void func_0026DA88(void *arg0)
{
    (void)func_0055F6A0(arg0, 0, 0);
    *(void **)((char *)arg0 + 0xD0) = D_00667BC8;
}
