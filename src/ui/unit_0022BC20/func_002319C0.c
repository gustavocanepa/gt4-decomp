typedef int s32;
typedef struct L { s32 pad; s32 *first; s32 *last; } L;
s32 func_002319C0(char *arg0) {
    L *p = (L *)(arg0 + 0x24);
    s32 *first = p->first;
    s32 *last = p->last;
    s32 r = 0;
    if (first != last) r = last[-1];
    return r;
}
