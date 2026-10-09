typedef int s32;

struct S00476768 {
    s32 unk0;
    s32 unk4;
};

extern "C" s32 func_00476870(struct S00476768 *arg0);

extern "C" s32 func_00476768(struct S00476768 *arg0, struct S00476768 *arg1) {
    arg0->unk0 = arg1->unk0;
    arg0->unk4 = arg1->unk4;
    return func_00476870(arg0);
}
