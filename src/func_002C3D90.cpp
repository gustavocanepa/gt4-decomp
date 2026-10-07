typedef int s32;

struct SomeStruct {
    char pad[0x14];
    s32 unk14;
};

extern void func_004609F8(s32);

extern "C" void func_002C3D90(struct SomeStruct *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk14;
    if (temp_v0 != 0) {
        func_004609F8(temp_v0);
    }
}
