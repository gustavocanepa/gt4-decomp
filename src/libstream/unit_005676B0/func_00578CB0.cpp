typedef int s32;

extern s32 malloc(s32);
extern void func_00577F80(void);

void func_00578CB0(s32 arg0)
{
    while (malloc(arg0) == 0) {
        func_00577F80();
    }
}
