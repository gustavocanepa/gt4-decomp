typedef float f32;

struct Obj_00397CE0 {
    char pad0[0x30];
    f32 m30;
    f32 m34;
    char pad38[0x28];
    char m60[4];
};

extern "C" void func_00397F18(Obj_00397CE0 *o);
extern "C" void func_003986E8(Obj_00397CE0 *o);
extern "C" void func_00397DA0(void *p, f32 t);
extern "C" void func_00397E70(Obj_00397CE0 *o);
extern "C" void func_00397D50(Obj_00397CE0 *o);
extern "C" void func_004568B0(f32 v);
extern "C" void func_004568A0(f32 v);

extern "C" void func_00397CE0(Obj_00397CE0 *o) {
    func_00397F18(o);
    func_003986E8(o);
    func_00397DA0(o->m60, 1.0f);
    func_00397E70(o);
    func_00397D50(o);
    func_004568B0(o->m34);
    func_004568A0(o->m34 * o->m30);
}
