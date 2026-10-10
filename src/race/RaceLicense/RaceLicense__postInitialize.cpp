typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void *(*fn)(void *, int);
};

struct Obj {
    char pad0[0x64];
    char *vtbl;
    char pad68[0x24EE0 - 0x68];
    int m24EE0;
    int m24EE4;
};

extern "C" void RaceBase__postInitialize(Obj *o);
extern "C" void CameraSys__CameraManager__initModeAsCourseIntroduction(void *p, int a);

extern "C" void RaceLicense__postInitialize(Obj *o) {
    RaceBase__postInitialize(o);
    if (o->m24EE0 && !o->m24EE4) {
        VEntry *e = (VEntry *)(o->vtbl + 0xD0);
        CameraSys__CameraManager__initModeAsCourseIntroduction(e->fn((char *)o + e->delta, 0), 0);
    }
}
