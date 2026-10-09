typedef int s32;

struct Obj {
    char pad[0x85C];
    s32 unk85C;
    s32 unk860;
};

extern "C" void func_004B84E8(Obj *arg0) {
    arg0->unk85C = 0;
    arg0->unk860 = 1;
}
