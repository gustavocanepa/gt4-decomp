typedef int s32;

struct Obj {
    char pad[0x308];
    s32 unk308;
};

extern "C" void func_002BE938(struct Obj *arg0, s32 arg1) {
    s32 temp = (s32)(arg1 != 0);
    s32 v = arg0->unk308;
    v = v & ~0x8;
    v = v | (temp << 3);
    arg0->unk308 = v;
}
