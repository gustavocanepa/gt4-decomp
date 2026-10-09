typedef int s32;

struct Elem {
    char pad0[0x3454];
    s32 unk3454;
};

struct Mid {
    char pad0[8];
    Elem **unk8;
};

struct Obj {
    char pad0[0x60];
    Mid *unk60;
};

extern "C" void func_003C0D98(Obj *arg0, s32 arg1, s32 arg2) {
    Mid *m;
    s32 flag;
    Elem **arr;
    Elem *e;

    m = arg0->unk60;
    flag = (arg1 != 0);
    arr = m->unk8;
    e = arr[arg2];
    e->unk3454 = flag;
}
