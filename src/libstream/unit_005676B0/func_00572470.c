typedef int s32;
void func_00572470(s32 *arg0) {
    s32 i;
    s32 *p;
    arg0[0] = 0;
    arg0[1] = 0;
    arg0[2] = 0;
    p = arg0 + 0x12;
    for (i = 0; i < 16; i++) {
        *p = 0;
        p--;
    }
}
