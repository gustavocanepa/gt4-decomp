/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Mutex { s32 w; };
extern "C" void func_00576788(Mutex *);
extern "C" void func_005767C0(Mutex *);

struct Guard {
    Mutex *m;
    Guard(Mutex *mx) : m(mx) { func_00576788(m); }
    ~Guard() { func_005767C0(m); }
};

struct Range { s32 a; s32 b; s32 c; void clear() { c = 0; b = 0; a = 0; } };
struct Obj { char pad[0x10]; Range r; char pad1C[0x104]; Mutex mutex; };

extern "C" void func_005DABC8(Obj *o) {
    Guard g(&o->mutex);
    o->r.clear();
}
