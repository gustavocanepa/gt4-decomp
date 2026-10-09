typedef int s32;

struct Obj_0064A550 {
    char pad[0x20];
    s32 (*unk20)(struct Obj_0064A550 *self);
};

extern "C" Obj_0064A550 *D_0064A550;
extern "C" void func_0057D9C0(const char *msg);

extern "C" s32 func_0050F0C8(void) {
    Obj_0064A550 *temp_a0;

    temp_a0 = D_0064A550;
    if (temp_a0->unk20(temp_a0) != 0) {
        func_0057D9C0("failed to clear ProductCache\n");
    }
    return 0;
}
