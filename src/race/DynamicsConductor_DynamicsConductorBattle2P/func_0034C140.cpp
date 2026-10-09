typedef int s32;
typedef unsigned short u16;

struct Obj {
    char pad[0xF850];
    u16 unkF850;
};

extern "C" s32 func_0034C140(Obj *arg0) {
    return arg0->unkF850 * 0xEA60;
}
