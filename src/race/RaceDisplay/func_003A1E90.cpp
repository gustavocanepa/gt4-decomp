typedef int s32;

struct Obj {
    char pad[0x5C];
    s32 unk5C;
};

extern "C" void func_003A1E90(struct Obj *arg0, s32 arg1, s32 arg2) {
    if (arg2 != 0) {
        arg0->unk5C = arg0->unk5C | arg1;
        return;
    }
    arg0->unk5C = arg0->unk5C & ~arg1;
}
