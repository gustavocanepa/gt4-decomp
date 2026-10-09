typedef int s32;

struct S0036FAB0 { char pad[0x104]; void *unk104; };

extern "C" void func_005C1628(struct S0036FAB0 *arg0);
extern "C" char D_006889A8;

extern "C" void func_00471FF0(struct S0036FAB0 *arg0, s32 arg1) {
    arg1 = arg1 & 1;
    arg0->unk104 = &D_006889A8;
    if (arg1) {
        func_005C1628(arg0);
        return;
    }
}
