typedef int s32;

struct Obj {
    char pad[4];
    s32 unk4;
};

extern "C" void *func_00603998(Obj **arg0) {
    Obj *p = *arg0;
    s32 n = p->unk4;
    char *p10 = (char *)p + 0x10;
    return p10 + n * 8;
}
