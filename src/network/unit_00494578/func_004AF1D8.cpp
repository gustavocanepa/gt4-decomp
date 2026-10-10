struct VEntry { short delta; short index; void (*fn)(void *); };
struct Conn {
    char pad[0x38]; void *owner;
    char pad2[0x80 - 0x3C]; int closed; int state;
    char pad3[0xA8 - 0x88]; char *vtbl;
};
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" void func_004AD648(void *, Conn *);

extern "C" void func_004AF1D8(Conn *c)
{
    int notify = 0;
    func_00576788(c);
    if (!c->closed) {
        if (c->owner) {
            func_004AD648(c->owner, c);
        } else {
            c->state = 4;
            notify = 1;
        }
    }
    func_005767C0(c);
    if (notify) {
        VEntry *e = (VEntry *)(c->vtbl + 0x48);
        e->fn((char *)c + e->delta);
    }
}
