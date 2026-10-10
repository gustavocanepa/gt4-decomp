/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ctx { char pad[0x6E14]; void *anim; };
struct Slot {
    char pad[0x10];
    unsigned short loop : 1;
    unsigned short reverse : 1;
};
extern "C" void *func_00479830(Slot *s, Ctx *c);
extern "C" void func_00473820(void *anim, void *target, int loop, int reverse, float t);

extern "C" void func_00479850(Slot *s, Ctx *c, float t)
{
    func_00473820(c->anim, func_00479830(s, c), s->loop, s->reverse, t);
}
