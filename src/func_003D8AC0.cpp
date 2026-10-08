typedef int s32;
typedef unsigned int u32;

struct Obj_003D8AC0 {
    char pad0[0x64];
    s32 unk64;
    char pad1[0x68 - 0x64 - 4];
    s32 unk68;
    char pad2[0x88 - 0x68 - 4];
    s32 unk88;
    char pad3[0xA4 - 0x88 - 4];
    u32 unkA4;
};

extern "C" void func_003D8AC0(struct Obj_003D8AC0 *arg0, s32 arg1) {
    struct Obj_003D8AC0 *self = arg0;

    if (self->unk64 != arg1) {
        self->unk64 = arg1;
        self->unk68 = 1;
        self->unkA4 = (self->unkA4 & 0xFFFF00FF) | 0x100;
        self->unk88 = 0;
    }
}
