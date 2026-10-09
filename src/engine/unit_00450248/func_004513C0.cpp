typedef float f32;
typedef unsigned int u32;

struct Struct_004513C0 {
    char pad0[0x4C];
    f32 unk4C[4];
};

extern "C" void func_004513C0(struct Struct_004513C0 *arg0, u32 arg1, f32 fparg0) {
    if (arg1 < 4u) {
        arg0->unk4C[arg1] = fparg0;
    }
}
