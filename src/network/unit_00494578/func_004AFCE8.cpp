extern "C" void func_004AF708(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00688FA0;

struct func_004AFCE8_arg0 {
    char pad0[0x20];
    void *unk20;
};

extern "C" void func_004AFCE8(struct func_004AFCE8_arg0 *arg0, int arg1) {
    arg0->unk20 = &D_00688FA0;
    func_004AF708(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
