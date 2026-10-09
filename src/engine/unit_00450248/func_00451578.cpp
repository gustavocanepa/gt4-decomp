typedef float f32;
typedef unsigned int u32;

struct Struct_00451578 {
    char pad0[0x74];
    f32 unk74[2];
};

extern "C" void func_00451578(struct Struct_00451578 *arg0, u32 arg1, f32 fparg0) {
    if (arg1 < 2u) {
        arg0->unk74[arg1] = fparg0;
    }
}
