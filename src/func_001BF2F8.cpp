typedef int s32;

struct Struct_001BF2F8 {
    char pad[0x14];
    s32 *unk14;
};

extern "C" void func_001C4A90(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_001BF2F8(Struct_001BF2F8 *arg0, s32 arg1) {
    s32 *temp_v0;

    temp_v0 = arg0->unk14;
    if (temp_v0 != 0) {
        func_001C4A90((s32)((char *)temp_v0 + 0x18C), arg1, 0);
    }
}
