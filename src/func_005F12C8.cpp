typedef int s32;

struct Obj {
    char pad[8];
    s32 unk8;
};

extern "C" void func_005F12C8(struct Obj *arg0, s32 arg1) {
    arg0->unk8 = arg0->unk8 + arg1;
}
