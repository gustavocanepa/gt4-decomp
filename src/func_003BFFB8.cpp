typedef int s32;

struct Obj {
    char pad[0x80];
    s32 unk80;
};

extern "C" void func_00394E70(s32 arg0);
extern char D_006214B0;

extern "C" void *func_003BFFB8(struct Obj *arg0) {
    s32 temp_v0 = arg0->unk80;

    if (temp_v0 != 0) {
        func_00394E70(temp_v0);
    }
    return &D_006214B0;
}
