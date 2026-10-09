typedef int s32;

struct Struct_00305550 {
    char pad0[0x10];
    s32 unk10;
};

extern "C" void func_00305550(Struct_00305550 *arg0, s32 *arg1) {
    s32 *p = &arg0->unk10;

    if (p != arg1) {
        *p = *arg1;
    }
}
