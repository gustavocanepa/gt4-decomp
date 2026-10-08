typedef int s32;

struct Obj00293B70 {
    char pad[0xB4];
    s32 unkB4;
};

extern "C" void func_00293B70(struct Obj00293B70 *arg0, s32 arg1) {
    s32 temp = (s32)(arg1 != 0);
    s32 v = arg0->unkB4;
    v = v & ~0x10;
    v = v | (temp << 4);
    arg0->unkB4 = v;
}
