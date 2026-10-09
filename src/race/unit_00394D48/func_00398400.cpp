typedef int s32;
typedef float f32;

struct Obj {
    char pad[0xB4];
    f32 unkB4;
    f32 unkB8;
    f32 unkBC;
    f32 unkC0;
    f32 unkC4;
    f32 unkC8;
};

extern "C" void func_00496548(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);

extern "C" void func_00398400(Obj *arg0, s32 arg1) {
    func_00496548(arg1, arg0->unkB4, arg0->unkB8, arg0->unkBC, arg0->unkC0, arg0->unkC4, arg0->unkC8);
}
