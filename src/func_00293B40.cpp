typedef int s32;

struct Obj {
    char pad[0xB4];
    s32 unkB4;
};

extern "C" void func_00293B40(struct Obj *arg0, s32 arg1) {
    s32 temp = (s32)(arg1 != 0);
    s32 v = arg0->unkB4;
    v = v & ~0x4;
    v = v | (temp << 2);
    arg0->unkB4 = v;
}
