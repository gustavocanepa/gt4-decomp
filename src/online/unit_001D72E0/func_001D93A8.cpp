typedef int s32;

struct Obj {
    char pad[0x108];
    s32 unk108;
    s32 unk10C;
};

extern "C" void func_001D93A8(s32 arg0, Obj *arg1) {
    arg1->unk10C = arg0 ^ 1;
    arg1->unk108 = 1;
}
