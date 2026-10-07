typedef int s32;

struct S { char pad[0x4C]; void *unk4C; };

extern "C" void func_005C1628(struct S *arg0);
extern "C" char D_006864F8;

extern "C" void func_005FF730(struct S *arg0, s32 arg1) {
    arg1 = arg1 & 1;
    arg0->unk4C = &D_006864F8;
    if (arg1) {
        func_005C1628(arg0);
        return;
    }
}
