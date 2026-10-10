extern "C" int func_0057F238(const char *a, const char *b);
extern "C" char D_0068BB20[];
extern "C" char D_00695448[];
extern "C" char D_00695468[];
extern "C" char D_006954C0[];
extern "C" char D_00695470[];
extern "C" char D_006954D8[];

extern "C" const char *func_001D4598(void)
{
    if (func_0057F238(D_0068BB20, D_00695448) == 0)
        return D_006954C0;
    if (func_0057F238(D_0068BB20, D_00695468) == 0)
        return D_00695470;
    return D_006954D8;
}
