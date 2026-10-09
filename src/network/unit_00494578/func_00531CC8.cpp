typedef int s32;

struct Obj {
    char pad[0x5C];
    s32 unk5C;
};

extern Obj *D_0064B47C;

extern "C" s32 func_00531CC8(void) {
    return D_0064B47C->unk5C;
}
