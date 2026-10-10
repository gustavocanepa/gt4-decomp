struct Part { char pad[0xD4]; char mD4[4]; };
struct VEntry {
    short delta;
    short index;
    Part *(*fn)(void *, int);
};
struct VObj {
    char pad[0x64];
    VEntry *vtbl;
};
static inline Part *vcall72(VObj *o, int id)
{
    VEntry *e = &o->vtbl[72];
    return e->fn((char *)o + e->delta, id);
}
extern "C" int AutomobileControlRecord__Manager__size(void *p, int n);

extern "C" int RaceSplitBattleBase__sizeReplayInputs(VObj *o)
{
    int a = AutomobileControlRecord__Manager__size(vcall72(o, 0x100)->mD4, 1);
    int b = AutomobileControlRecord__Manager__size(vcall72(o, 0x101)->mD4, 1);
    return a + b;
}
