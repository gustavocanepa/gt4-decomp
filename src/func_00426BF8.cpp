typedef int s32;
typedef unsigned int u32;

struct Obj {
    char pad0[0xD4];
    s32 unkD4;
    char pad1[0x1C4 - 0xD4 - 4];
    s32 unk1C4;
    s32 unk1C8;
};

extern "C" void func_00426BF8(Obj *arg0, u32 arg1) {
    s32 temp_v0;

    arg0->unk1C4 = arg1;
    temp_v0 = arg1 >= 2U;
    arg0->unk1C8 = temp_v0;
    arg0->unkD4 = temp_v0;
}
