typedef int s32;

struct Obj {
    char pad[0xE8];
    s32 unkE8;
};

extern "C" void func_00233DB8(struct Obj *arg0, s32 arg1) {
    arg0->unkE8 = (arg0->unkE8 & ~1) | (arg1 != 0);
}
