typedef float f32;

struct Obj {
    char pad0[0x6C];
    f32 angle;
};

extern "C" void func_004A5348(int on);
extern "C" void func_004A53F8(void);
extern "C" void func_004A7844(f32 x, f32 y, f32 z);

extern "C" void func_0039F698(Obj *o) {
    func_004A5348(1);
    func_004A53F8();
    func_004A7844(0.0f, -o->angle, 0.0f);
    func_004A5348(0);
}
