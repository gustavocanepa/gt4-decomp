typedef int s32;

extern "C" void func_00309348(s32 arg0, s32 *arg1);
extern "C" s32 func_002CBDD0(s32 arg0);

extern "C" void func_002CBED0(s32 arg0, s32 arg1) {
    s32 s0 = arg0;
    s32 local = func_002CBDD0(0);

    func_00309348(s0, &local);
}
