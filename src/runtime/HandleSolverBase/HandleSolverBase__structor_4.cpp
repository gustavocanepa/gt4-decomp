typedef int s32;

struct S { char pad[0x4C]; void *unk4C; };

extern "C" void func_005C1628(struct S *arg0);
extern "C" char HandleSolverBase__vtable;

extern "C" void HandleSolverBase__structor_4(struct S *arg0, s32 arg1) {
    arg1 = arg1 & 1;
    arg0->unk4C = &HandleSolverBase__vtable;
    if (arg1) {
        func_005C1628(arg0);
        return;
    }
}
