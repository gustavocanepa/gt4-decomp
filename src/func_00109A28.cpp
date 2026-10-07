typedef int s32;

struct SomeStruct {
    char pad[0x58];
    s32 unk58;
};

extern void func_0055FAB0(s32);

extern "C" void func_00109A28(struct SomeStruct *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk58;
    if (temp_v0 != 0) {
        func_0055FAB0(temp_v0);
    }
}
