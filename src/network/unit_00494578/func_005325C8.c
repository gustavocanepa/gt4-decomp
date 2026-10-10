typedef int s32;
extern s32 D_00868844;
extern s32 D_0086A8C8[];
s32 func_0053A300(char *a, s32 b, s32 c, s32 d, s32 e, s32 f);
void func_005325C8(s32 arg0, char *arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 r = func_0053A300(arg1, arg0, arg2, arg3, arg4, 0);
    if (arg1 == 0) {
        D_00868844 = r;
    } else {
        D_0086A8C8[*(s32 *)(arg1 + 0x15C)] = r;
    }
}
