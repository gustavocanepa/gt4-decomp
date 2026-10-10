typedef int s32;

extern void *D_006863A0;
extern "C" void *func_003C26A8(void *);

struct func_003C2710_arg0 {
    char pad0[0x4];
    void *unk4;
};

struct func_003C2710_r0 {
    char pad0[0x4];
    void *unk4;
};

extern "C" void *func_003C2710(struct func_003C2710_arg0 *arg0) {
    void *r0 = func_003C26A8(arg0);
    if (r0 != 0) {
        ((struct func_003C2710_r0 *)r0)->unk4 = &D_006863A0;
        *(void **)(r0) = arg0->unk4;
        arg0->unk4 = r0;
    }
    return r0;
}
