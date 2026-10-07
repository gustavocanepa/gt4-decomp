typedef int s32;

struct SomeStruct {
    char pad[0x14];
    s32 unk14;
};

extern void func_001C4D20(s32);

extern "C" void func_001BF0A8(struct SomeStruct *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk14;
    if (temp_v0 != 0) {
        func_001C4D20(temp_v0);
    }
}
