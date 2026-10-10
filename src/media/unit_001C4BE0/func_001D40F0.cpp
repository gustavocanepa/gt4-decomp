extern "C" int func_001D40F0(short *p, short *end)
{
    short *start = p;
    short v = *p++;
    while (*p == v && p < end)
        p++;
    return p - start;
}
