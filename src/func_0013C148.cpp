typedef int s32;

extern "C" void func_0013BDC0(s32 *arg0, s32 arg1);
extern "C" void func_00145970(s32 arg0, s32 arg1);
extern "C" void func_0013BD68(s32 *arg0, s32 arg1);

extern "C" void func_0013C148(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 buf0[8];
    s32 buf1[4];

    if (arg2 > 0) {
        func_0013BDC0(buf0, arg1);
        s32 val0 = buf0[0];
        s32 *p1 = buf1;
        func_0013BDC0(p1, arg3);
        func_00145970(val0, p1[0]);
        func_0013BD68(p1, 2);
        func_0013BD68(buf0, 2);
    }
}
