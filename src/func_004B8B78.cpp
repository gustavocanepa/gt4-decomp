extern "C" int func_0057F260(const char *s);
extern const char D_006B04E8[];

extern "C" int func_004B8B78(int c) {
    int n = func_0057F260(D_006B04E8);
    for (int i = 0; i < n; i++) {
        if (D_006B04E8[i] == c)
            return i + 1;
    }
    return -1;
}
