typedef int s32;

extern "C" s32 func_00197798(s32 arg0);
extern char D_0001E634[];

extern "C" s32 func_0019AA18(s32 arg0, s32 arg1) {
    s32 v0 = func_00197798(arg1);
    s32 v1 = 0;
    if (v0 != 0) {
        v1 = *(s32 *)(D_0001E634 + v0);
    }
    return v1;
}
