typedef int s32;
typedef unsigned int u32;

struct Obj_003BAC80 {
    char pad0[8];
    u32 m8;
    char padC[4];
    s32 m10;
};

extern "C" u32 RaceInput__getButtonDown(void *x);
extern "C" void func_003BAC20(Obj_003BAC80 *o);

extern "C" void func_003BAC80(Obj_003BAC80 *o, void *x) {
    if (RaceInput__getButtonDown(x) & 0x30) {
        func_003BAC20(o);
        o->m8 = (o->m8 & 0xFFFF00FF) | 0x100;
        o->m10 = 6;
    }
}
