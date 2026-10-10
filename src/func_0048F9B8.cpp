extern "C" void *func_004900B8(void *mgr, const char *name);
extern "C" void func_00490180(void *player, void *item);
extern "C" void *D_00624980;
extern "C" void *D_00624984;

extern "C" void func_0048F9B8(const char *name)
{
    if (!name || !D_00624980)
        return;
    void *item = func_004900B8(D_00624980, name);
    if (D_00624984 && item)
        func_00490180(D_00624984, item);
}
