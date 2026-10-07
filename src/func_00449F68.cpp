typedef int s32;
typedef long long s64;

struct Elem {
    char pad[0x8];
    s64 unk8;
};

struct Obj {
    char pad[0x8];
    Elem *unk8;
};

extern "C" s64 func_00449F68(Obj *arg0, s32 arg1) {
    char *base = (char *)arg0->unk8;
    Elem *p = (Elem *)(base + arg1 * 0x10);
    return p->unk8;
}
