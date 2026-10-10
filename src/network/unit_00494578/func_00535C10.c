typedef int s32;
extern char D_008686B8[];
void func_00531738(char *a);
void func_00535D48(void *a, s32 i);
void func_00535C10(char *arg0) {
    s32 i;
    if (arg0 != 0) {
        for (i = 0; i < 0x40; i++) func_00535D48(arg0, i);
        func_00531738(D_008686B8 + *(s32 *)(arg0 + 0x15C) * 4);
    }
}
