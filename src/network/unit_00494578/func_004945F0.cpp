typedef int s32;

struct Obj { char pad[0x960]; s32 f960; char pad964[0x14]; s32 f978; };
extern "C" void func_00494A28(Obj *);

extern "C" void func_004945F0(Obj *o, s32 v) {
    if (o->f960 != v) {
        func_00494A28(o);
        o->f978 = 1;
        o->f960 = v;
    }
}
