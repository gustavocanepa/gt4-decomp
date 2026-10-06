extern "C" void *func_0030A678(void);
extern "C" void *func_00560548(void *arg0);
extern "C" char D_00662D60[];

extern "C" void *func_00221CB0(void *arg0)
{
    func_0030A678();
    *(void **)((char *)arg0 + 4) = D_00662D60;
    return func_00560548((char *)arg0 + 0x10);
}
