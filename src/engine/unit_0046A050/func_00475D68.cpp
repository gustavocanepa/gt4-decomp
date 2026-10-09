typedef int s32;

struct Obj {
    char pad[0x194];
    s32 unk194;
    s32 unk198;
};

extern "C" void func_00475D68(Obj *arg0, s32 arg1, s32 arg2) {
    arg0->unk194 = arg1;
    arg0->unk198 = arg2;
}
