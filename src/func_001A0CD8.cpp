extern "C" void *func_0030A678(void);
extern "C" void *func_00446F90(void *arg0);
extern "C" char D_0065DF98[];

extern "C" void *func_001A0CD8(void *arg0)
{
    func_0030A678();
    *(void **)((char *)arg0 + 4) = D_0065DF98;
    return func_00446F90((char *)arg0 + 0x10);
}
