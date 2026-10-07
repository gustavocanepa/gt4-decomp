typedef int s32;
typedef unsigned char u8;
typedef float f32;

extern "C" void func_0045B0A0(s32 arg0, u8 *arg1, s32 arg2);

extern "C" void func_0045B018(s32 arg0, f32 arg1) {
    f32 buf = arg1;
    func_0045B0A0(arg0, (u8 *)&buf, 4);
}
