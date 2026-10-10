extern const char D_006A2370[];
extern const char D_006A2378[];
extern const char D_006A2388[];
extern "C" int func_0057DA20(char *buf, const char *fmt, ...);
extern "C" const char *func_003AEAE8(const char *key);

extern "C" const char *func_003B03B8(int id)
{
    const char *s;
    if (id < 0 || id == 0xFF)
        return D_006A2370;
    s = D_006A2370;
    if ((unsigned int)id < 13) {
        char key[32];
        func_0057DA20(key, D_006A2378, id);
        s = func_003AEAE8(key);
        if (s == 0)
            s = D_006A2388;
    }
    return s;
}
