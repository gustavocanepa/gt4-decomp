typedef int s32;

struct Obj {
    char pad[0x1670];
    s32 unk1670;
    s32 unk1674;
};

extern "C" void func_005F6FF0(Obj *arg0, s32 arg1, s32 arg2) {
    arg0->unk1670 = arg1;
    arg0->unk1674 = (arg1 == 0) ? 0 : (arg2 != 0);
}
