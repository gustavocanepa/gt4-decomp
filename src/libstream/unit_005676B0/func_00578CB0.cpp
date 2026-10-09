typedef int s32;

extern s32 func_00575DC8(s32);
extern void func_00577F80(void);

void func_00578CB0(s32 arg0)
{
    while (func_00575DC8(arg0) == 0) {
        func_00577F80();
    }
}
