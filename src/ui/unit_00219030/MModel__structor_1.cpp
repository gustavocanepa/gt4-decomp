typedef int s32;

struct S0021A728 { char pad[0x48]; void *unk48; };

extern "C" void func_005C1628(struct S0021A728 *arg0);
extern "C" char MModel__vtable;

extern "C" void MModel__structor_1(struct S0021A728 *arg0, s32 arg1) {
    arg1 = arg1 & 1;
    arg0->unk48 = &MModel__vtable;
    if (arg1) {
        func_005C1628(arg0);
        return;
    }
}
