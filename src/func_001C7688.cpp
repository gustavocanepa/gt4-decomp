typedef int s32;

struct Obj {
    char pad[0x8F0];
    s32 unk8F0;
    s32 unk8F4;
};

extern "C" void func_001C7688(Obj *arg0, s32 arg1, s32 arg2) {
    arg0->unk8F0 = arg1;
    arg0->unk8F4 = arg2;
}
