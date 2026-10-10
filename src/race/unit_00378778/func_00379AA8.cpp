typedef int s32;
typedef float f32;

struct Info_00379AA8 {
    char pad0[0x14];
    f32 m14;
    char pad18[0x28];
};

extern "C" void func_004A7550(Info_00379AA8 *info);
extern "C" f32 func_0057D5A8(f32 x);
extern "C" void func_004A4550(s32 id, s32 value);
extern "C" f32 D_00623874;

extern "C" void func_00379AA8(void) {
    Info_00379AA8 info;
    func_004A7550(&info);
    func_004A4550(10, (s32)((-func_0057D5A8(info.m14) * 0x1.715476p+0f + D_00623874) * 256.0f));
}
