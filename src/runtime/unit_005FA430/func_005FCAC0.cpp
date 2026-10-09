typedef int s32;

struct Elem {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

struct S {
    Elem arr[0x400];
    s32 count;
};

extern "C" void func_005FCAC0(S *arg0, Elem *arg1) {
    s32 count = arg0->count;
    Elem *dst = (Elem *)((char *)arg0 + count * 12);

    if (dst != 0) {
        *dst = *arg1;
    }
    arg0->count = arg0->count + 1;
}
