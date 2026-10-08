typedef int s32;

struct Obj {
    char pad[0x98];
    s32 unk98;
};

extern "C" void func_00265E80(Obj *arg0, s32 arg1) {
    s32 temp = (s32)(arg1 != 0);
    s32 v = arg0->unk98;
    v = v & ~0x8000;
    v = v | (temp << 15);
    arg0->unk98 = v;
}
