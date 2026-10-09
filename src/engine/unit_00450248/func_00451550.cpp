typedef float f32;
typedef unsigned int u32;

struct Elem00451550 {
    char pad[0xBC];
    f32 unkBC;
};

extern "C" void func_00451550(void *arg0, u32 arg1, f32 fparg0) {
    if (arg1 < 4U) {
        ((struct Elem00451550 *)((char *)arg0 + arg1 * 0x38))->unkBC = fparg0;
    }
}
