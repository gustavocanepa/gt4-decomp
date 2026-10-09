typedef int s32;

struct Obj00233E18 {
    char pad[0xE8];
    s32 unkE8;
};

extern "C" void func_00233E18(struct Obj00233E18 *arg0, s32 arg1) {
    s32 temp = (s32)(arg1 != 0);
    s32 v = arg0->unkE8;
    v = v & ~0x4;
    v = v | (temp << 2);
    arg0->unkE8 = v;
}
