typedef signed char s8;

struct Obj {
    char pad[0x4];
    s8 unk4;
    s8 unk5;
    s8 unk6;
    s8 unk7;
    s8 unk8;
};

extern "C" void func_00438FD8(struct Obj *arg0) {
    arg0->unk4 = 1;
    arg0->unk5 = 1;
    arg0->unk6 = 1;
    arg0->unk7 = 1;
    arg0->unk8 = 1;
}
