typedef int s32;

struct Obj {
    char pad[0x308];
    s32 unk308;
};

extern "C" void func_002BE968(struct Obj *arg0, s32 arg1) {
    s32 temp = (s32)(arg1 != 0);
    s32 v = arg0->unk308;
    v = v & ~0x10;
    v = v | (temp << 4);
    arg0->unk308 = v;
}
