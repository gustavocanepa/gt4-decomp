extern "C" void *HandleSolverBase__structor_0(void *arg0);
extern "C" char FixedHandleSolver__vtable[];

struct S00415470 {
    char pad[0x4C];
    void *unk4C;
};

extern "C" void FixedHandleSolver__structor_0(S00415470 *arg0)
{
    HandleSolverBase__structor_0(arg0);
    arg0->unk4C = FixedHandleSolver__vtable;
}
