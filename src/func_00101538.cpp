struct VEntry {
    short delta;
    short index;
    void (*fn)(void *);
};
struct VObj {
    char pad[0x64];
    VEntry *vtbl;
};
static inline void vcall3(VObj *o)
{
    VEntry *e = &o->vtbl[3];
    e->fn((char *)o + e->delta);
}
extern "C" void func_00576788(void *lock);
extern "C" void func_005767C0(void *lock);
extern "C" char D_006D67B0[];
extern VObj *D_00617D40;
extern int D_00617D44;
extern int D_00617D48;

extern "C" void func_00101538(int v)
{
    func_00576788(D_006D67B0);
    if (D_00617D40)
        vcall3(D_00617D40);
    D_00617D44 = v;
    D_00617D48 = 1;
    func_005767C0(D_006D67B0);
}
