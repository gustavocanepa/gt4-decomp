typedef int s32;

extern "C" void func_0021D9D0(s32 *arg0, s32 arg1);
extern "C" s32 func_0021FAD0(s32 arg0);
extern "C" void func_0021FAD8(s32 arg0, s32 arg1);
extern "C" void func_0021D978(s32 *arg0, s32 arg1);

extern "C" void MMovieFace__refOther(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 buf0[4];
    s32 buf1[4];

    if (arg2 > 0) {
        func_0021D9D0(buf0, arg1);
        s32 *p1 = buf1;
        func_0021D9D0(p1, arg3);
        s32 base0 = buf0[0];
        s32 result = func_0021FAD0(p1[0]);
        func_0021FAD8(base0, result);
        func_0021D978(p1, 2);
        func_0021D978(buf0, 2);
    }
}
