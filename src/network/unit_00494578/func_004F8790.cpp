typedef int s32;

struct Obj {
    char pad0[0x16C];
    s32 unk16C;
    s32 unk170;
    s32 unk174;
    s32 unk178;
    s32 unk17C;
    s32 unk180;
    s32 unk184;
};

extern "C" void func_004F8790(Obj *arg0) {
    arg0->unk174 = 0;
    arg0->unk16C = 0;
    arg0->unk170 = 0;
    arg0->unk178 = 0;
    arg0->unk17C = 0;
    arg0->unk180 = 0;
    arg0->unk184 = 0;
}
