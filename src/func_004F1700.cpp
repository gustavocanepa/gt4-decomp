typedef int s32;

extern s32 func_004F16B8(s32);
extern void func_00577F80(void);

void func_004F1700(s32 arg0)
{
    while (func_004F16B8(arg0) == 0) {
        func_00577F80();
    }
}
