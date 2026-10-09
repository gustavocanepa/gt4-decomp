typedef int s32;

struct S005E8B18 {
    char pad[0x308];
    s32 unk308;
};

extern "C" void func_005E8B18(struct S005E8B18 *arg0, s32 arg1) {
    s32 temp = (s32)(arg1 != 0);
    s32 v = arg0->unk308;
    v = v & ~0x2;
    v = v | (temp << 1);
    arg0->unk308 = v;
}
