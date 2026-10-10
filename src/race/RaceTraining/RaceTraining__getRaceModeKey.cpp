typedef short s16;
typedef int s32;

struct VEntry_003BCBD0 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, void *);
};

struct Obj_003BCBD0 {
    char pad0[0x64];
    VEntry_003BCBD0 *vtbl;
};

extern "C" int RaceBase__getRaceModeKeyString(int arg0);

extern "C" int RaceTraining__getRaceModeKey(struct Obj_003BCBD0 *arg0, void *arg1) {
    VEntry_003BCBD0 *e = (VEntry_003BCBD0 *)((char *)arg0->vtbl + 0x300);
    s32 r = e->fn((char *)arg0 + e->delta, arg1);

    return RaceBase__getRaceModeKeyString(r);
}
