typedef int s32;

struct Obj {
    char pad[0x308];
    s32 unk308;
};

extern "C" void func_005E8AE8(struct Obj *arg0, s32 arg1) {
    arg0->unk308 = (arg0->unk308 & ~1) | (arg1 != 0);
}
