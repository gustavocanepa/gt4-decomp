typedef int s32;

struct Obj0045AEB0 {
    char pad0[4];
    char *unk4;
    char *unk8;
};

extern "C" void func_0045AEB0(Obj0045AEB0 *arg0, s32 arg1) {
    char *p = arg0->unk8;

    if (p < arg0->unk4) {
        *p = arg1;
        p = arg0->unk8;
    }
    arg0->unk8 = p + 1;
}
