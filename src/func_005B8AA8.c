/* compiler: ee-gcc2.9-991111 */
struct Timer {
    int m0;
    int m4;
    int id;
    int flags;
    long long base;
    long long total;
    char pad[0x20];
};

extern long long func_005B8400(void);

long long func_005B8AA8(int handle)
{
    struct Timer *t = (struct Timer *)(((unsigned int)handle >> 10) << 6);
    long long total;

    if (handle < 0 || (handle & 0x3FF) != t->id)
        return -1;
    total = t->total;
    if (t->flags & 1)
        total += func_005B8400() - t->base;
    return total;
}
