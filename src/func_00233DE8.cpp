typedef int s32;

struct Obj {
    char pad[0xE8];
    s32 unkE8;
};

extern "C" void func_00233DE8(struct Obj *arg0, s32 arg1) {
    s32 temp = (s32)(arg1 != 0);
    s32 v = arg0->unkE8;
    v = v & ~2;
    v = v | (temp << 1);
    arg0->unkE8 = v;
}
