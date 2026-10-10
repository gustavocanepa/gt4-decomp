struct Race { char pad[0x1003e]; short count; };
unsigned char func_003FA228(Race *);
short func_003FA248(Race *r)
{
    int n = func_003FA228(r);
    int v;
    if (n == 0)
        return 0;
    v = r->count;
    if (v < n * 60) {
        int w = v + 1;
        r->count = w;
        v = w;
    }
    return v;
}
