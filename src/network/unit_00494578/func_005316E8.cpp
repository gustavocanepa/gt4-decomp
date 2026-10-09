typedef int s32;

struct Obj {
    char pad[0x5C];
    s32 unk5C;
};

extern Obj *D_0064B47C;

extern "C" void func_005316E8(s32 arg0) {
    D_0064B47C->unk5C = arg0;
}
