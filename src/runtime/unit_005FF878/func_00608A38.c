typedef int s32;

struct Obj { char pad[0xC0]; s32 fC0; char padC4[0x24]; s32 fE8; s32 fEC; };
struct Obj *func_006065A0(void *);

struct Obj *func_00608A38(void *key, s32 a, s32 b) {
    struct Obj *o = func_006065A0(key);
    if (o) {
        o->fEC = b;
        o->fE8 = a;
        o->fC0 = 0;
    }
    return o;
}
