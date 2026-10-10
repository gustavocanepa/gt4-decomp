extern "C" void RaceEntryBase__structor_1(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00679880;

struct func_0033B840_arg0 {
    char pad0[0x20];
    void *unk20;
};

extern "C" void func_0033B840(struct func_0033B840_arg0 *arg0, int arg1) {
    arg0->unk20 = &D_00679880;
    RaceEntryBase__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
