extern "C" void RaceDisplayObjectBase__structor_1(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *RaceMessageDisplay__vtable;

struct RaceMessageDisplay__structor_4_arg0 {
    char pad0[0x14];
    void *unk14;
};

extern "C" void RaceMessageDisplay__structor_4(struct RaceMessageDisplay__structor_4_arg0 *arg0, int arg1) {
    arg0->unk14 = &RaceMessageDisplay__vtable;
    RaceDisplayObjectBase__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
