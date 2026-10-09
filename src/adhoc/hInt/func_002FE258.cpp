typedef int s32;

struct Obj {
    char pad[0x10];
    s32 unk10;
};

extern "C" void func_002FE258(Obj *arg0, s32 arg1) {
    arg0->unk10 = arg1;
}
