typedef int s32;

extern void *D_00689F50;
extern "C" void *func_0057DD98(void *);

struct func_0057DC60_arg0 {
    void *unk0;
    void *unk4;
};

extern "C" void *func_0057DC60(struct func_0057DC60_arg0 *arg0, s32 arg1) {
    void *r0 = func_0057DD98(arg0);
    arg0->unk0 = &D_00689F50;
    arg0->unk4 = (void *)(arg1);
    return r0;
}
