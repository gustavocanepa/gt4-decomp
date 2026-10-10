extern "C" void RaceDisplayObjectBase__structor_1(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *RaceMeterBase__vtable;

struct RaceMeterBase__structor_7_arg0 {
    char pad0[0x14];
    void *unk14;
};

extern "C" void RaceMeterBase__structor_7(struct RaceMeterBase__structor_7_arg0 *arg0, int arg1) {
    arg0->unk14 = &RaceMeterBase__vtable;
    RaceDisplayObjectBase__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
