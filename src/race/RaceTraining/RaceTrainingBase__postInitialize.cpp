typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void *(*fn)(void *, int);
};

struct Obj {
    char pad0[0x64];
    char *vtbl;
    char pad68[0x125F8 - 0x68];
    int m125F8;
    int m125FC;
};

extern "C" void RaceBase__postInitialize(Obj *o);
extern "C" void CameraSys__CameraManager__initModeAsCourseIntroduction(void *p, int a);

extern "C" void RaceTrainingBase__postInitialize(Obj *o) {
    RaceBase__postInitialize(o);
    if (o->m125F8 && !o->m125FC) {
        VEntry *e = (VEntry *)(o->vtbl + 0xD0);
        CameraSys__CameraManager__initModeAsCourseIntroduction(e->fn((char *)o + e->delta, 0), 0);
    }
}
