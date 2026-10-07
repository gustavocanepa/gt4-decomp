extern "C" void *func_0030A678(void);
extern "C" void *func_0048F270(void *arg0);
extern "C" char D_0066C460[];

extern "C" void *func_0029D678(void *arg0)
{
    func_0030A678();
    *(void **)((char *)arg0 + 4) = D_0066C460;
    return func_0048F270((char *)arg0 + 0x10);
}
