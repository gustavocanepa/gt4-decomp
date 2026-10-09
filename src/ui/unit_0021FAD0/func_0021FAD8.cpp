typedef int s32;

struct SomeStruct {
    char pad[0x114];
    s32 unk114;
};

extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void func_0021FAD8(struct SomeStruct *arg0, s32 *arg1) {
    s32 *s1 = &arg0->unk114;

    if (s1 != arg1) {
        s32 temp_s0 = *arg1;
        if (temp_s0 != 0) {
            func_003285A8(temp_s0);
        }
        s32 temp_v0 = *s1;
        if (temp_v0 != 0) {
            func_003285F8(temp_v0);
        }
        *s1 = temp_s0;
    }
}
