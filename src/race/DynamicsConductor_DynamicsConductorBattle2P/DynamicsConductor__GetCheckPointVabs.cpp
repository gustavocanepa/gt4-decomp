struct VEntry { short delta; short index; int (*fn)(void *); };
struct Obj { char pad0[0xCBD8]; void *course; char pad1[0x10140 - 0xCBDC]; char *vtbl; };
extern "C" float RaceCourse__getCheckPoint(void *, int, int);

extern "C" float DynamicsConductor__GetCheckPointVabs(Obj *o, int idx)
{
    VEntry *e = (VEntry *)(o->vtbl + 0x150);
    if (e->fn((char *)o + e->delta) - 2 < idx) return -1.0f;
    return RaceCourse__getCheckPoint(o->course, idx, 0);
}
