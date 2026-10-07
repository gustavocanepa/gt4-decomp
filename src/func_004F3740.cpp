typedef int s32;

struct Obj {
    char pad[0x18];
    s32 unk18;
};

struct Local {
    s32 a;
    void *b;
};

extern "C" s32 func_004F0C38(s32 arg0, const char *arg1);
extern "C" void func_004F87E8(s32 arg0, s32 arg1);
extern "C" void func_004F0B08(s32 arg0, void *arg1);

extern "C" s32 D_00645570;

extern "C" void func_004F3740(Obj *arg0, s32 arg1) {
    s32 var_s0;
    Local local;

    var_s0 = arg1;
    if (var_s0 == 0) {
        var_s0 = (s32)&D_00645570;
    }
    local.a = var_s0;
    local.b = arg0;
    if (func_004F0C38(var_s0, "SessionBeginCallback") != 0) {
        func_004F0B08(local.a, local.b);
        return;
    }
    func_004F87E8(var_s0, arg0->unk18);
    func_004F0B08(local.a, local.b);
}
