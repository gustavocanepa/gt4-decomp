typedef int s32;

struct Obj00305590 {
    char pad[0x10];
    s32 unk10;
};

extern "C" s32 func_003166B8(s32 arg0);

extern "C" void func_00305590(struct Obj00305590 *arg0, s32 arg1) {
    s32 local;
    s32 *s0 = &arg0->unk10;

    local = func_003166B8(arg1);
    if (s0 != &local) {
        *s0 = local;
    }
}
