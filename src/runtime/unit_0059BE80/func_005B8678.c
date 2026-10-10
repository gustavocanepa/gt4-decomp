/* compiler: ee-gcc2.9-991111 */
struct State {
    int pad0[2];
    int active;
    int pad1;
    int count;
};
extern volatile struct State D_006592F0;

int func_005B8678(int *used, int *func_00575DA0)
{
    volatile struct State *s = &D_006592F0;
    if (s->active < 0)
        return 0x80008001;
    if (used)
        *used = s->count;
    if (func_00575DA0)
        *func_00575DA0 = 0x80 - s->count;
    return 0;
}
