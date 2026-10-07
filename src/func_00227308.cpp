extern "C" void *func_0030A678(void);
extern "C" void *func_005DA8A0(void *arg0);
extern "C" char D_006649F0[];

extern "C" void *func_00227308(void *arg0)
{
    func_0030A678();
    *(void **)((char *)arg0 + 4) = D_006649F0;
    return func_005DA8A0((char *)arg0 + 0x10);
}
