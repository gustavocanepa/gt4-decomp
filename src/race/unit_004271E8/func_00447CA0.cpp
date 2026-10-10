extern "C" const char *func_00443E60(void *table, int id);
extern "C" char *func_005A609C(char *dst, const char *src); /* strcpy */
extern "C" char D_006235A8[];

extern "C" int func_00447CA0(int id, char *out)
{
    const char *s = func_00443E60(D_006235A8, id);
    if (s) {
        func_005A609C(out, s);
        return 1;
    }
    out[0] = 0;
    return 0;
}
