typedef int s32;

struct Obj {
    char pad[0x98];
    s32 unk98;
};

extern "C" void func_002662B0(Obj *arg0, s32 arg1) {
    s32 temp = (s32)(arg1 != 0);
    s32 v = arg0->unk98;
    v = v & 0x7FFFFFFF;
    v = v | (temp << 31);
    arg0->unk98 = v;
}
