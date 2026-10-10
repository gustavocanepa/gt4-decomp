typedef int s32;
extern s32 D_00863770;
extern void *D_0064B4B4;
void func_0051B9B8(s32 a, s32 b);
void func_0051B9F0(s32 arg0) {
    s32 i;
    if (arg0 != 0) {
        if (D_00863770 != 0) {
            for (i = 0; i < 0x40; i++) func_0051B9B8(arg0, i);
        }
    }
    {
        char *p = *(char **)0x64B4B4;
        if (p != 0) *(s32 *)(p + 0x10C) = 0;
    }
}
