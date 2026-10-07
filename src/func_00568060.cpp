typedef int s32;

struct S00655320 {
    s32 unk0;
    s32 unk4;
};

extern S00655320 D_00655320[];

extern "C" void func_00568060(s32 arg0, s32 arg1, s32 arg2) {
    S00655320 *p = &D_00655320[arg0];
    p->unk0 = arg1;
    p->unk4 = arg2;
}
