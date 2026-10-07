typedef int s32;

struct SomeStruct {
    char pad[4];
    s32 unk4;
};

extern void func_003E7360(s32);

extern "C" void func_003E7410(struct SomeStruct *arg0) {
    s32 temp_v0 = arg0->unk4;
    if (temp_v0 != 0) {
        func_003E7360(temp_v0);
    }
}
