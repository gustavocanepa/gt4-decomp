/* compiler: ee-gcc2.9-991111 */
struct Obj { char pad[0x20]; unsigned int list[1]; };
struct Obj *func_0058B280(void *, unsigned short);

int func_005860F0(void *ctx, unsigned short id, int idx)
{
    struct Obj *o = func_0058B280(ctx, id);
    int n;
    unsigned int *l;
    if (o == 0) return 0;
    l = o->list;
    for (n = 0; l[n] != 0xFFFFFFFF; n++)
        ;
    if (idx >= n) return 0;
    return l[idx];
}
