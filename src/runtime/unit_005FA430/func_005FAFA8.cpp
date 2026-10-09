typedef int s32;

struct Obj {
    char pad[0x8];
    s32 *unk8;
};

extern "C" void func_005FAFA8(Obj *arg0, s32 arg1, s32 arg2) {
    arg0->unk8[arg1] = arg2;
}
