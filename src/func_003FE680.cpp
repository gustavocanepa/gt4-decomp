typedef int s32;

struct Obj_003FE680 {
    char pad0[0x18];
    s32 unk18;
};

extern "C" s32 func_003FE4C8(void);

extern "C" void func_003FE680(void *arg0, struct Obj_003FE680 *arg1) {
    struct Obj_003FE680 *s0 = arg1;

    if (s0->unk18 == 0) {
        s0->unk18 = func_003FE4C8();
    }
}
