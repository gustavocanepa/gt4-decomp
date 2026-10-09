extern "C" void *RaceSinglePlayer__structor_0(void *);
extern "C" void DynamicsConductorSinglePlayer__structor_1(void *);
extern "C" void *func_003721D8(void *);
extern "C" void *CameraBase__structor_0(void *);
extern "C" void func_003B08C8(void *);
extern "C" void func_003B05A8(void *);
extern "C" char RacePhotoDevelop__vtable[];
extern "C" char DevelopCamera__vtable[];
extern "C" char D_006792D8[];
extern "C" char D_00688780[];
extern "C" char D_006792C0[];

inline void *operator new(unsigned int, void *p) { return p; }

#define W(p, o) (*(int *)((char *)(p) + (o)))
#define P(p, o) (*(void **)((char *)(p) + (o)))

struct Inner {
    Inner() {}
};

struct Blank {
    Inner i;
    char pad[0x4E];
};

struct Vec3 {
    Vec3() { x = 0.0f; y = 1.0f; z = 0.0f; }
    float x, y, z;
};

struct Lens {
    Blank b[4];
    Vec3 v[4];
};

struct LensSetBase {
    LensSetBase() { vt = D_00688780; }
    void *vt;
};

struct LensSet : LensSetBase {
    LensSet() { a = 0; b = 0; }
    Lens lens[2];
    int a, b;
};

struct LensSets {
    LensSet s[6];
};

struct Part {
    Part() { func_003B08C8(this); func_003B05A8(pad + 0x6A0); }
    char pad[0x700];
};

struct SlotBase {
    SlotBase() { vt = D_006792C0; }
    void *vt;
};

struct Slot : SlotBase {
    Slot() { a = 0; b = 0; }
    int pad4[3];
    Part parts[2];
    int a, b;
    int padE18[2];
};

struct Slots {
    Slot s[6];
};

extern "C" void DevelopCamera__structor_0(char *self)
{
    char *cam = self + 0x22740;
    char *base = self + 0x233C0;

    RaceSinglePlayer__structor_0(self);
    P(self, 0x64) = RacePhotoDevelop__vtable;
    DynamicsConductorSinglePlayer__structor_1(self + 0x125C0);
    func_003721D8(cam);
    P(cam, 0) = DevelopCamera__vtable;
    W(cam, 0xC40) = 0;
    P(cam, 0xC44) = base;
    CameraBase__structor_0(base);
    P(base, 0) = D_006792D8;
    W(base, 0x8C) = 0;
    W(base, 0x90) = 0;

    new (self + 0x23454) LensSets;
    new (self + 0x245B0) Slots;
    new (self + 0x29A70) Slots;
    P(self, 0x70) = self + 0x125C0;
    W(self, 0x2EF34) = 0;
    W(self, 0x2EF38) = 0;
    W(self, 0x2EF30) = 0;
}
