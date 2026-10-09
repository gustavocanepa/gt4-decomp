typedef int s32;

extern s32 func_004FEEA0(s32);
extern void func_00577F80(void);

void func_004FEE60(s32 arg0)
{
    while (func_004FEEA0(arg0) == 0) {
        func_00577F80();
    }
}
