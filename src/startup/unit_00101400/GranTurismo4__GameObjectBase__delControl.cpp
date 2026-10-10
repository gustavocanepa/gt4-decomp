typedef int s32;

struct SomeStruct {
    char pad[0x58];
    s32 unk58;
};

extern void func_0055FAF8(s32);

extern "C" void GranTurismo4__GameObjectBase__delControl(struct SomeStruct *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk58;
    if (temp_v0 != 0) {
        func_0055FAF8(temp_v0);
    }
}
