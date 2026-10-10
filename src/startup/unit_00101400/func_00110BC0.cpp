typedef int s32;
typedef unsigned int u32;

struct C_00110BC0 { char pad[0x18]; void *m18; };
struct B_00110BC0 { C_00110BC0 *m0; };
struct A_00110BC0 { char pad[8]; B_00110BC0 *m8; };
struct Obj_00110BC0 { char pad[0x60]; A_00110BC0 *m60; };

extern "C" u32 func_0035E3F0(void *p);

extern "C" s32 func_00110BC0(Obj_00110BC0 *o, u32 *best) {
    s32 r = 0;
    u32 v = func_0035E3F0(o->m60->m8->m0->m18);
    if (v < *best) {
        *best = v;
        r = 1;
    }
    return r;
}
