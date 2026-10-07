typedef int s32;

struct S00265E50 {
    char pad0[0x98];
    s32 unk98;
};

extern "C" void func_00265E50(struct S00265E50 *arg0, s32 arg1) {
    s32 temp = (s32)(arg1 != 0);
    s32 v = arg0->unk98;
    v = v & ~0x4000;
    v = v | (temp << 14);
    arg0->unk98 = v;
}
