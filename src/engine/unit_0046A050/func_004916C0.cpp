typedef int s32;
struct Item { Item *next; int a, b; };
struct Pool { char hdr[0x3C]; Item *free; Item items[40]; };
extern Pool D_008496D8;
extern "C" void *func_005A48D8(void *, int, unsigned int);
static inline void ctor(Pool *self)
{
    self->free = 0;
    func_005A48D8(self->hdr, 0, sizeof(self->hdr));
    func_005A48D8(self->items, 0, sizeof(self->items));
    for (unsigned int i = 1; i < 40; i++) self->items[i].next = &self->items[i - 1];
    self->free = &self->items[39];
}

extern "C" void func_004916C0(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) ctor(&D_008496D8);
}
