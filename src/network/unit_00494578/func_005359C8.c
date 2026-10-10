typedef int s32;
extern char D_008686C8[];
void func_00531738(char *a);
s32 func_005359C8(void) {
    s32 i;
    for (i = 0; i < 64; i++) {
        func_00531738(D_008686C8 + i * 4);
    }
    return 0;
}
