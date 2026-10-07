typedef int s32;

extern "C" void func_004AE370(s32 arg0, s32 arg1, void *arg2, s32 arg3);

extern "C" s32 func_004AE230(s32 arg0, s32 arg1, s32 arg2) {
    s32 s0 = arg0;
    struct { s32 a; s32 b; } local;

    local.a = 0;
    local.b = 0;
    func_004AE370(arg0, arg1, &local, arg2);
    return s0;
}
