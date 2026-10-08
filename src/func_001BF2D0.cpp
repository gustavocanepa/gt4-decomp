typedef int s32;

struct Obj {
    char pad[0x14];
    s32 unk14;
};

extern "C" void func_001C4A90(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_001BF2D0(struct Obj *arg0, s32 arg1) {
    s32 temp_v0 = arg0->unk14;
    if (temp_v0 != 0) {
        func_001C4A90(temp_v0 + 0x17C, arg1, 0);
    }
}
