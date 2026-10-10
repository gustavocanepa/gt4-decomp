extern "C" const char *func_0041B3D0(int index);
extern "C" int func_0057F238(const char *a, const char *b); /* strcmp */

extern "C" int func_0041B4D0(const char *name)
{
    if (name != 0) {
        for (int i = 0; i < 20; i++) {
            if (func_0057F238(func_0041B3D0(i), name) == 0)
                return i;
        }
    }
    return -1;
}
