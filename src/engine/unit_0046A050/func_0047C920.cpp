typedef int s32;
typedef float f32;

struct Val {
    s32 type;
    f32 v;
    Val(f32 x) {
        type = 6;
        v = x;
    }
};

struct Obj {
    char pad[0x50];
    s32 unk50;
};

extern "C" void func_00480FA0(s32, s32);

extern "C" Val func_0047C920(Obj *o, s32 a, s32 b) {
    func_00480FA0(b, a);
    return Val((f32)o->unk50);
}
