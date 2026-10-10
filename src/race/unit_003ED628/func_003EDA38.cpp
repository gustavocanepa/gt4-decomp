extern "C" void *func_003ED7C0(void *holder);
extern "C" void func_003ED768(void *holder, void *obj);
extern "C" void *func_004638D8(void *desc, int flags);
extern "C" char D_00621F78[];
extern "C" char D_00621F58[];

extern "C" void *func_003EDA38(void)
{
    void *p = func_003ED7C0(D_00621F78);
    if (!p) {
        func_003ED768(D_00621F78, func_004638D8(D_00621F58, 0));
        p = func_003ED7C0(D_00621F78);
    }
    return p;
}
