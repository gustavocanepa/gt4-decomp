typedef int s32;

struct Obj {
    char pad[0x8];
    s32 unk8;
};

extern s32 D_008414C0;

extern "C" s32 hValue__isValid(Obj *arg0) {
    return arg0->unk8 != D_008414C0;
}
