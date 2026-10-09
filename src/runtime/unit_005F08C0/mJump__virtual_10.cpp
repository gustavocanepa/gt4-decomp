typedef int s32;

struct Obj {
    char pad[8];
    s32 unk8;
};

extern "C" void mJump__virtual_10(struct Obj *arg0, s32 arg1) {
    arg0->unk8 = arg0->unk8 + arg1;
}
