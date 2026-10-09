typedef int s32;

struct Obj {
    char pad0[0x174];
    s32 unk174;
    s32 unk178;
    s32 unk17C;
    s32 unk180;
    s32 unk184;
    s32 unk188;
};

extern "C" void func_00146628(Obj *arg0) {
    arg0->unk174 = 0;
    arg0->unk180 = -1;
    arg0->unk178 = 0;
    arg0->unk17C = 0;
    arg0->unk184 = 0;
    arg0->unk188 = 0;
}
