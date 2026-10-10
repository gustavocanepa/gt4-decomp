/* compiler: ee-gcc2.9-991111 */
struct Pending {
    char pad0[0x34];
    int arg;
    int pending;
    int f3C;
    int (*fn)(int);
};

extern struct Pending D_0087E1C0;

int func_0058A158(void) {
    struct Pending *p = &D_0087E1C0;
    int r;
    if (p->pending != 0) {
        p->pending = 0;
        r = p->fn(p->arg);
        if (r < 0) {
            return r;
        }
    }
    return 0;
}
