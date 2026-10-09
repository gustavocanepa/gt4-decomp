typedef int s32;

struct Obj {
    char pad[0xB4];
    s32 unkB4;
};

extern "C" void func_00293AE0(struct Obj *arg0, s32 arg1) {
    arg0->unkB4 = (arg0->unkB4 & ~1) | (arg1 != 0);
}
