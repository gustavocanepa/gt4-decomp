typedef int s32;

struct Obj001BF5C0 {
    char pad[0x14];
    s32 unk14;
};

extern "C" void func_001C4A90(s32 arg0, s32 arg1, s32 arg2);

static inline s32 xor1(s32 x) {
    s32 t = x;
    return t ^ 1;
}

extern "C" void func_001BF5C0(struct Obj001BF5C0 *arg0, s32 arg1) {
    s32 temp_v0 = arg0->unk14;

    if (temp_v0 != 0) {
        func_001C4A90(temp_v0 + 0x1DC, arg1, xor1(arg1));
    }
}
