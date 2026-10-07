typedef int s32;

struct Inner {
    char pad[0x14];
    s32 unk14;
};

struct Outer {
    char pad[0x7C];
    Inner *unk7C;
};

extern "C" void func_003979E0(Outer **arg0, s32 arg1) {
    Outer *temp_a0;

    temp_a0 = *arg0;
    if (temp_a0 != 0) {
        temp_a0->unk7C->unk14 = arg1;
    }
}
