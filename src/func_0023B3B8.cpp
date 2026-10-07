extern "C" void *func_0030A678(void);
extern "C" void *func_002273C8(void *arg0);
extern "C" char D_00665C70[];

extern "C" void *func_0023B3B8(void *arg0)
{
    func_0030A678();
    *(void **)((char *)arg0 + 4) = D_00665C70;
    return func_002273C8((char *)arg0 + 0x10);
}
