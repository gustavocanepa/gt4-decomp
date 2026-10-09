typedef int s32;

struct Obj {
    char pad[0x9C];
    s32 unk9C;
};

extern Obj *D_00618318;

extern "C" s32 func_0010AEC0(void) {
    Obj *p = D_00618318;
    if (p == 0) {
        return 0;
    }
    return p->unk9C;
}
