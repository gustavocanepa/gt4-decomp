typedef int s32;

struct Elem {
    s32 unk0;
    s32 unk4;
};

extern Elem D_00655320[];

extern "C" void func_00568040(s32 arg0) {
    Elem *p = &D_00655320[arg0];
    p->unk0 = 0;
    p->unk4 = 0;
}
