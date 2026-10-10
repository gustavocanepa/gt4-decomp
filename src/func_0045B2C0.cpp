typedef int s32;

extern "C" s32 func_0045B2C0(const char *s) {
    s32 r = 0;
    for (s32 i = 0; i < 4 && *s != 0; i++)
        r |= *s++ << (i * 8);
    return r;
}
