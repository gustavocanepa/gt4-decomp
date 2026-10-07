struct S003789E8 {
    char pad[4];
    int unk4;
};

extern "C" void func_003717F8(void *arg0);
extern "C" void func_003FAC90(void *arg0, int arg1);
extern "C" void func_00371800(void *arg0, void *arg1);

extern "C" void func_003789E8(void *arg0, void *arg1, void *arg2, S003789E8 *arg3) {
    void *s0 = (char *) arg0 + 0xDD0;
    void *s1 = (char *) arg0 + 0xE28;
    if (arg3->unk4 != 0) {
        func_003717F8(s1);
    }
    func_003FAC90(s0, 1);
    func_00371800(s1, s0);
}
