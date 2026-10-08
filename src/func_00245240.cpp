typedef int s32;

struct Obj00245240 {
    char pad[0x104];
    s32 unk104;
};

extern "C" void func_002B71D0(void *arg0, s32 arg1);

extern "C" void *func_00245240(void *arg0, struct Obj00245240 *arg1) {
    void *s0 = arg0;

    func_002B71D0(arg0, arg1->unk104);
    return s0;
}
