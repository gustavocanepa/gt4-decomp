typedef int s32;

struct Obj {
    char pad[0xCD0];
    s32 unkCD0;
};

extern s32 D_006213E8;

extern "C" void func_00387E28(Obj *arg0, s32 arg1) {
    arg0->unkCD0 = arg1;
    D_006213E8 = arg1;
}
