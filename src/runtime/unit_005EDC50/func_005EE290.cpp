typedef int s32;

struct Obj {
    char pad[0x30];
    s32 *unk30;
};

extern "C" s32 func_005EE290(Obj *arg0, s32 arg1) {
    s32 *p = arg0->unk30;
    s32 *entry = p + arg1;
    return *entry;
}
